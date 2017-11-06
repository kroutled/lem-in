/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:39:16 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/06 16:07:21 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "./libft/libft.h"
#include <fcntl.h>

typedef struct	s_room t_room;
typedef struct	s_args t_args;
typedef struct	s_vars t_vars;

struct s_room
{
	char		*name;
	int			start;
	int			end;
	t_room		*roomlinks[100000];
};

struct	s_args
{
	t_room		*rooms[100000];
	char		*line;
	char		**data;
};

struct	s_vars
{
	int		count;
	int		start;
	int		end;
	char	*numants;
};

#endif
