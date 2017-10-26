/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:39:06 by kroutled          #+#    #+#             */
/*   Updated: 2017/10/26 18:01:55 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

int		ft_startend(t_args *args, t_vars *vars)
{
	if (ft_strstr(args->data[vars->count], "start"))
	{
		ft_putendl("start");
	}
	else if(ft_strstr(args->data[vars->count], "end"))
	{
		ft_putendl("end");
	}
	return (0);
}

void	ft_setrooms(t_args *args, t_vars *vars)
{
	t_room	*rooms;
	ft_bzero(&rooms, sizeof(t_room));
	vars->count = 0;

	while (args->data[vars->count])
	{
		if (args->data[vars->count][0] == '#')
		{
			if (ft_strstr(args->data[vars->count], "start"))
			{
				vars->count++;
				rooms->start = 1;
				rooms->name = &args->data[vars->count][0];
				ft_putnbr(rooms->start);
				ft_putendl(rooms->name);
			}
		}
		else
		{
			vars->count++;
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
			vars->numants = args->data[vars->count];
			break;
		}
		vars->count++;
	}
	ft_putendl(vars->numants);
}

void	ft_anthill(t_args *args, t_vars *vars)
{
	ft_numants(args, vars);
	ft_setrooms(args, vars);
}

int main(int ac, char **av)
{
	int 	fd;
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
		fd = open(av[1], O_RDONLY);
		args.line = ft_readfile(fd);
		args.data = ft_strsplit(args.line, '\n');
		ft_anthill(&args, &vars);
	}
	return (0);	
}
