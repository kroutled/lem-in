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
typedef struct	s_list	t_list;
typedef struct	s_ants	t_ants;

struct s_room
{
	char		*name;
	int			start;
	int			end;
	 int			full;
	 int			visited;
	t_room		*roomlinks[100000];
};

struct	s_args
{
	t_room		*rooms[100000];
	t_ants		**ants;
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

struct	s_list
{	
	char			*data;
	struct s_list	*next;
};

struct	s_ants
{
	char	*ant_name;
	char	*room;
	int		fin;
	int		index;
};

void	ft_roomcreate(t_args *args, t_vars *vars);
void	ft_tunnels(t_args *args, t_vars *vars);
void	ft_frees(t_args *args);

#endif
