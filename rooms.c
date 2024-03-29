/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:48:39 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/21 13:23:57 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_roomcreate(t_args *args, t_vars *vars)
{
	if (ft_arrlen(args->args) > 3)
		ft_error();
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
	vars->r_count++;
}

void	ft_set_anthill(t_args *args, t_vars *vars)
{
	args->args = ft_strsplit(args->line, ' ');
	if (args->args[0] == '\0')
		ft_error();
	else if (args->args[1] == NULL)
		ft_tunnels(args, vars);
	else
		ft_roomcreate(args, vars);
}
