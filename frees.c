/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:21:21 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/21 09:21:30 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void	ft_free_paths(t_args *args)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (args->paths[i])
	{
		j = 0;
		while (args->paths[i][j])
		{
			free(args->paths[i][j]);
			j++;
		}
		free(args->paths[i]);
		i++;
	}
	free(args->paths);
}

void	ft_free_rooms(t_args *args)
{
	int		i;

	i = 0;
	while (args->rooms[i])
	{
		free(args->rooms[i]->name);
		free(args->rooms[i]);
		i++;
	}
}

void    ft_free_ants(t_args *args)
{
	int		i;

	i = 0;
	while (args->ants[i])
	{
		free(args->ants[i]->ant_name);
		free(args->ants[i]);
		i++;
	}
	free(args->ants);
}
