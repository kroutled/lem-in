/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:39:06 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/21 13:29:29 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_ant_setup(t_args *args, t_vars *vars)
{
	int	i;

	i = 0;
	args->ants = (t_ants **)ft_memalloc(sizeof(t_ants*) * (vars->numants + 1));
	while (i < vars->numants)
	{
		args->ants[i] = (t_ants*)ft_memalloc(sizeof(t_ants));
		args->ants[i]->ant_name = ft_itoa(i + 1);
		args->ants[i]->room = args->rooms[vars->start]->name;
		args->ants[i]->fin = 0;
		args->ants[i]->index = 1;
		i++;
	}
}

void	ft_startend_checkroom(t_args *args, t_vars *vars)
{
	vars->start = 0;
	vars->end = 0;
	while (args->rooms[vars->start]->start == 0)
	{
		if(args->rooms[++vars->start] == NULL)
			ft_error();
	}
	while (args->rooms[vars->end]->end == 0)
	{
		if(args->rooms[++vars->end] == NULL)
			ft_error();
	}
	args->rooms[vars->start]->full = vars->numants;
}

void	ft_startend(t_args *args, t_vars *vars)
{
	if (ft_strstr(args->line, "start"))
		vars->start = 1;
	if (ft_strstr(args->line, "end"))
		vars->end = 1;
}

void	ft_anthill(t_args *args, t_vars *vars)
{
	while (get_next_line(0, &args->line) != 0)
	{
		ft_putendl(args->line);
		if (vars->count < 1 && ft_isdigit((args->line[0])))
		{
			vars->numants = ft_atoi(args->line);
			if (vars->numants == 0)
				ft_error();
			vars->count++;
		}
		else if (vars->count > 0)
		{
			if (args->line[0] == '#')
				ft_startend(args, vars);
			else
			{
				ft_set_anthill(args, vars);
			}
		}
		ft_frees(args);
	}
	ft_putstr("\n");
}

int		main(void)
{
	t_args	args;
	t_vars	vars;

	ft_bzero(&args, sizeof(t_args));
	ft_bzero(&vars, sizeof(t_vars));
	ft_anthill(&args, &vars);
	if (vars.count == 0)
		ft_error();
	ft_startend_checkroom(&args, &vars);
	ft_ant_setup(&args, &vars);
	ft_checktunnels(&args, &vars);
	if (!args.paths[0])
		ft_error();
	while (args.rooms[vars.end]->full < vars.numants)
	{
		vars.ai = 0;
		ft_loop_ants(&args, &vars);
		ft_putstr("\n");
	}
	ft_free_rooms(&args);
	ft_free_paths(&args);
	ft_free_ants(&args);
	return (0);
}
