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
    
}

void    ft_can_move(t_args *args, t_vars *vars, int *loop)
{

}