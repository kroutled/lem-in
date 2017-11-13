/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:39:16 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/13 13:08:33 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "./libft/libft.h"
#include <fcntl.h>

typedef struct	s_room	t_room;
typedef struct	s_args	t_args;
typedef struct	s_vars	t_vars;
typedef struct	s_paths	t_paths;
typedef struct	s_ants	t_ants;

struct s_room
{
	char		*name;
	int			start;
	int			end;
	int			full;
	t_room		*roomlinks[100000];
};

struct	s_args
{
	t_room		*rooms[100000];
	char		*line;
	char		**args;
	char		**links;
};

struct	s_vars
{
	int		fd;
	int		count;
	int		start;
	int		end;
	int		numants;
	int		r_count;
	int		f_rcnt;
	int		s_rcnt;
};

struct	s_paths
{
	char			*data;
	struct s_paths	*next;
};

struct	s_ants
{
	int		ant_name;
	char	*room;
};

void	ft_roomcreate(t_args *args, t_vars *vars);
void	ft_setpaths();

#endif
