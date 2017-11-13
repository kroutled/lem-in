/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:55:42 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/13 13:08:42 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
