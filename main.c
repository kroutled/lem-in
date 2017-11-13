/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:39:06 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/10 17:00:39 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void	ft_startend_checkroom(t_args *args, t_vars *vars)
{
	vars->start = 0;
	vars->end = 0;
	while (args->rooms[vars->start]->start == 0)
	{
		vars->start++;
	}
	while (args->rooms[vars->end]->end == 0)
	{
		vars->end++;
	}
	args->rooms[vars->start]->full = vars->numants;
}

void	ft_tunnels(t_args *args, t_vars *vars)
{
	int		cnt;
	int		cnt2;

	cnt = 0;
	cnt2 = 0;
	(void)vars;
	args->links = ft_strsplit(args->args[0], '-');
	if (ft_arrlen(args->links) > 2)
		exit(0);
	else
	{
		vars->f_rcnt = 0;
		while (ft_strcmp(args->rooms[vars->f_rcnt]->name, args->links[0]) != 0)
			vars->f_rcnt++;
		vars->s_rcnt = 0;
		while (ft_strcmp(args->rooms[vars->s_rcnt]->name, args->links[1]) != 0)
			vars->s_rcnt++;
		while (args->rooms[vars->f_rcnt]->roomlinks[cnt] != NULL)
			cnt++;
		while (args->rooms[vars->s_rcnt]->roomlinks[cnt2] != NULL)
			cnt2++;
		args->rooms[vars->f_rcnt]->roomlinks[cnt] = args->rooms[vars->s_rcnt];
		args->rooms[vars->s_rcnt]->roomlinks[cnt2] = args->rooms[vars->f_rcnt];
	}
}

void	ft_startend(t_args *args, t_vars *vars)
{
	if (ft_strstr(args->line, "start"))
		vars->start = 1;
	if (ft_strstr(args->line, "end"))
		vars->end = 1;
}

void	ft_frees(t_args *args)
{
	if (args->line != NULL)
	{
		free(args->line);
		args->line = NULL;
	}
	if (args->args != NULL)
	{
		ft_free2d(args->args);
		args->args = NULL;
	}
	if (args->links != NULL)
	{
		ft_free2d(args->links);
		args->links = NULL;
	}
}

void	ft_anthill(t_args *args, t_vars *vars)
{
	while (get_next_line(vars->fd, &args->line) != 0)
	{
		if (vars->count < 1 && ft_isdigit((args->line[0])))
		{
			vars->numants = ft_atoi(args->line);
			vars->count++;
		}
		else if (vars->count > 0)
		{
			if (args->line[0] == '#')
				ft_startend(args, vars);
			else
			{
				args->args = ft_strsplit(args->line, ' ');
				if (args->args[0] == '\0')
					exit(0);
				else if (args->args[1] == NULL)
					ft_tunnels(args, vars);
				else
					ft_roomcreate(args, vars);
			}
		}
		ft_frees(args);
	}
}

int	main(int ac, char **av)
{
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
		vars.fd = open(av[1], O_RDONLY);
		if (vars.fd == -1)
		{
			ft_putendl("File does not exist");
			exit(0);
		}
		ft_anthill(&args, &vars);
		ft_startend_checkroom(&args, &vars);
		close(vars.fd);
	}
	return (0);
}
