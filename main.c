/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:39:06 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/09 16:51:21 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

int		ft_arrlen(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_roomcreate(t_args *args, t_vars *vars)
{
	if (ft_arrlen(args->args) > 3)
		exit(0);
	args->rooms[vars->r_count] = (t_room*)ft_memalloc(sizeof(t_room));
	args->rooms[vars->r_count]->name = ft_strdup(args->args[0]);
	if (vars->start == 1)
	{
		args->rooms[vars->r_count]->start = 1;
		vars->start = 0;
	}
	if (vars->end == 1)
	{
		args->rooms[vars->r_count]->end = 1;
		vars->end = 0;
	}	
}

void	ft_startend(t_args *args, t_vars *vars)
{
	if (ft_strstr(args->line, "start"))
		vars->start = 1;	
	if (ft_strstr(args->line, "end"))
		vars->end = 1;
}

void	ft_frees(t_args *args)
{
	if (args->line != NULL)
	{
		free(args->line);
		args->line = NULL;
	}
	if (args->args != NULL)
	{
		ft_free2d(args->args);
		args->args = NULL;
	}
}

void	ft_anthill(t_args *args, t_vars *vars)
{
	vars->count = 0;
	while (get_next_line(vars->fd, &args->line) != 0)
	{
		if (vars->count < 1 && ft_isdigit((args->line[0])))
		{
			vars->numants = ft_atoi(args->line);
			vars->count++;
		}
		else if (vars->count > 0)
		{
			if (args->line[0] == '#')
			{
				ft_startend(args, vars);
			}
			else
			{
				args->args = ft_strsplit(args->line, ' ');
				if (args->args[0] == '\0')
					exit(0);
				else if(args->args[1] == NULL)
				{
					ft_putendl("links");
				}
				else
				{
					ft_roomcreate(args, vars);
				}
			}
			
		}
		ft_frees(args);
	}
}

int main(int ac, char **av)
{
	t_args	args;
	t_vars	vars;

	ft_bzero(&args, sizeof(t_args));
	ft_bzero(&vars, sizeof(t_vars));
	if (ac != 2)
	{
		ft_putendl("Usage: ./lem-in [file]");
	}
	else
	{
		vars.fd = open(av[1], O_RDONLY);
		ft_anthill(&args, &vars);
		close(vars.fd);
	}
	return (0);	
}
