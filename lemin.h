/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:39:16 by kroutled          #+#    #+#             */
/*   Updated: 2017/11/21 13:12:29 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_room	t_room;
typedef struct s_args	t_args;
typedef struct s_vars	t_vars;
typedef struct s_paths	t_paths;
typedef struct s_ants	t_ants;

struct	s_room
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
	char		***paths;
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
	int		ri;
	int		ai;
	int		pi;
	int		move;
	int		cnt;
};

struct	s_paths
{
	char	*data;
	t_paths	*next;
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
void	ft_createfile(t_paths *head, int fd);
void	ft_find_routes(int fd, t_paths *head, t_paths *list, t_room *sroom);
void	ft_checktunnels(t_args *args, t_vars *vars);
void	ft_loop_ants(t_args *args, t_vars *vars);
void	ft_loop_paths(t_args *args, t_vars *vars);
void	ft_loop_rooms(t_args *args, t_vars *vars);
void	ft_can_move(t_args *args, t_vars *vars, int *loop);
int		ft_ants_from(t_args *args, t_vars *vars);
void	ft_ants_to(t_args *args, t_vars *vars, int *loop);
void	ft_sortpaths(char ***arr);
void	ft_frees(t_args *args);
void	ft_free_paths(t_args *args);
void	ft_free_rooms(t_args *args);
void	ft_free_ants(t_args *args);
void	ft_error(void);
void	ft_set_anthill(t_args *args, t_vars *vars);

#endif
