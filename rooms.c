/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:48:39 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/10 14:37:51 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	vars->r_count++;
}