/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:39:06 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/06 17:44:25 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>
/*
int		ft_start(t_args *args, t_vars *vars)
{
	if (ft_strstr(args->data[vars->count], "start"))
	{
		vars->count++;
		room->start = 1;
		room->name = ft_strdup(&args->data[vars->count][0]);
		ft_putendl(room->name);
	}
	if (ft_strstr(args->data[vars->count], "end"))
	{
		vars->count++;
		room->end = 1;
		room->name = ft_strdup(&args->data[vars->count][0]);
	}
	return (0);
}

void	ft_checkroom_info(t_args *args, t_vars *vars)
{
	while (args->data[vars->count])
	{
		if (args->data[vars->count][0] == '#')
		{
			if (ft_strstr(args->data[vars->count], "start"))
			{
				vars->count++;

			}
		}
		//1.getname
		//2.start or end?
		vars->count++;
	}
}
*/
void	ft_setrooms(t_args *args, t_vars *vars)
{
	vars->count = 0;
	vars->i = 0;
	//t_checkroom_info(args, vars);
	ft_putendl("hello 1");
	while(args->rooms[vars->count])
	{
		ft_putendl("hello 2");
		//insert room info;ft_checkroom_info(args, vars);
		while (args->data[vars->i])
		{
			ft_putendl("hello 3");
			if (args->data[vars->i][0] == '#')
			{
				ft_putendl("hello 4");
				if (ft_strstr(args->data[vars->i], "start"))
				{
					vars->i++;
					args->rooms[vars->count]->name = args->data[vars->i];
					ft_putendl(args->rooms[vars->count]->name);
					ft_putendl("hello bitches");
				}
			}
			//1.getname
			//2.start or end?
		}
		vars->count++;
	}
}

void	ft_numants(t_args *args, t_vars *vars)
{
	vars->count = 0;
	while (args->data[vars->count])
	{
		if (ft_isdigit(args->data[vars->count][0]))
		{
			vars->numants = ft_atoi(args->data[vars->count]);
			break;
		}
		vars->count++;
	}
}

void	ft_anthill(t_args *args, t_vars *vars)
{
	ft_numants(args, vars);
	ft_setrooms(args, vars);
}

int main(int ac, char **av)
{
	int 	fd;
	t_args	*args;
	t_vars	*vars;

	args = (t_args*)ft_memalloc(sizeof(t_args));
	vars = (t_vars*)ft_memalloc(sizeof(t_vars));
	if (ac != 2)
	{
		ft_putendl("Usage: ./lem-in [file]");
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		args->line = ft_readfile(fd);
		args->data = ft_strsplit(args->line, '\n');
		ft_anthill(args, vars);
	}
	return (0);	
}