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
  
//int		ft_startend(t_args *args, t_vars *vars)
//{
//
//}

void	ft_setrooms(t_args *args, t_vars *vars)
{
	t_room	*room;
	room = (t_room*)ft_memalloc(sizeof(t_room));
	vars->count = 0;
	int			i;

	i = 0;
	while (args->data[vars->count])
	{
		if (args->data[vars->count][0] == '#')
		{
			if (ft_strstr(args->data[vars->count], "start"))
			{
				vars->count++;
				room->start = 1;
				room->name = &args->data[vars->count][0];
				//ft_putendl(room->name);
				args->rooms[i] = room;
				i++;
				//ft_putendl(args->data[vars->count]);
				//ft_putstr("\n");
				//ft_putendl(rooms->name);
			}
			else if (ft_strstr(args->data[vars->count], "end"))
			{
				vars->count++;
				room->end = 1;
				room->name = &args->data[vars->count][0];
				args->rooms[i] = room;
				i++;
				//ft_putendl(room->name);
			}
		}
		else
		{
			if (ft_isdigit(args->data[vars->count][0]))
			{
				//ft_putendl("he");
			}
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
	//ft_putendl(vars->numants);
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
