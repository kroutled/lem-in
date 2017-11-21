/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:21:55 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/21 09:22:00 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>
void    ft_loop_rooms(t_args *args, t_vars *vars)
{
    int     loop;

    loop = 0;
    while (args->rooms[vars->ri])
    {
        if ((ft_strcmp(args->paths[vars->pi]
            [args->ants[vars->ai]->index], args->rooms[vars->ri]->name) == 0) 
            && (ft_strcmp(args->paths[vars->pi]
            [args->ants[vars->ai]->index - 1], args->ants[vars->ai]->room) == 0))
        {
            ft_can_move(args, vars, &loop);
            if (loop == 1)
                break ;
        }
        vars->ri++;
    }
}

void    ft_loop_paths(t_args *args, t_vars *vars)
{
    while (args->paths[vars->pi])
    {
        vars->ri = 0;
        if (args->ants[vars->ai]->index < ft_arrlen(args->paths[vars->pi]))
        {
            ft_loop_rooms(args, vars);
        }
        if (vars->move == 1)
        {
            vars->move= 0;
            break ;
        }
        vars->pi++;
    }
}

void    ft_loop_ants(t_args *args, t_vars *vars)
{
    while (args->ants[vars->ai])
    {
        vars->pi = 0;
        if (args->ants[vars->ai]->fin != 1)
        {
            ft_loop_paths(args, vars);
        }
        vars->ai++;
    }
}
