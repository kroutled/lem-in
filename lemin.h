#ifndef LEMIN_H
# define LEMIN_H

#include "./libft/libft.h"

typedef struct	s_room t_room;
typedef struct	s_anthill t_anthill;

struct s_room
{
	char		*name;
	int			start;
	int			end;
	t_room		*roomlinks[100000];
}

struct	anthill
{
	t_room		*rooms[100000];
}

#endif
