#include "lemin.h"

void    ft_looprooms(t_args *args, t_vars *vars)
{
    int     loop;

    loop = 0;
    while (args->rooms[vars->ri])
    {
        
    }
}

void    ft_looppaths(t_args *args, t_vars *vars)
{
    while (args->paths[vars->pi])
    {
        vars->ri = 0;
        if (args->ants[vars->ai]->index < ft_arrlen(args->paths[vars->pi]))
        {
            ft_looprooms(args, vars);
        }
        if (vars->move == 1)
        {
            vars->move= 0;
            break ;
        }
        vars->pi++;
    }
}

void    ft_loopants(t_args *args, t_vars *vars)
{
    while (args->ants[vars->ai])
    {
        vars->pi = 0;
        if (args->ants[vars->ai]->fin != 1)
        {
            ft_looppaths(args, vars);
        }
        vars->ai++;
    }
}