#include "lemin.h"

void    ft_ants_to(t_args *args, t_vars *vars, int *loop)
{
    args->rooms[vars->ri]->full += 1;
    args->ants[vars->ai]->room = args->rooms[vars->ri]->name;
    ft_putstr("L");
    ft_putstr(args->ants[vars->ai]->ant_name);
    ft_putstr("-");
    ft_putstr(args->rooms[vars->ri]->name);
    ft_putstr(" ");
    vars->move = 1;
    vars->cnt = 0;
    *loop = 1;
}

int     ft_ants_from(t_args *args, t_vars *vars)
{
    if (ft_strcmp(args->paths[vars->pi][args->ants[vars->ai]->index - 1],
         args->rooms[vars->cnt]->name) == 0)
    {
        args->rooms[vars->cnt]->full -= 1;
        return (1);
    }
    return (0);
}

void    ft_can_move(t_args *args, t_vars *vars, int *loop)
{
    if (args->rooms[vars->ri]->full == 0 && args->rooms[vars->ri]->end == 0)
    {
        ft_ants_to(args, vars, loop);
        while (args->rooms[vars->cnt])
        {
            if (ft_ants_from(args, vars) == 1)
                break;
            vars->cnt++;
        }
        args->ants[vars->ai]->index += 1;
    }
    else if (args->rooms[vars->ri]->end == 1)
    {
        args->ants[vars->ai]->fin = 1;
        ft_ants_to(args, vars, loop);
        while (args->rooms[vars->cnt])
        {
            if (ft_ants_from(args, vars) == 1)
                break ;
            vars->cnt++;
        }
        args->ants[vars->ai]->index += 1;
    }
}