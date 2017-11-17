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

//saves the routes to a file to be read into 3d arrs
void	ft_createfile(t_paths *head, int fd)
{
	while (head && head->data)
	{
		write(fd, head->data, ft_strlen(head->data));
		write(fd, " ", 1);
		head = head->next;
	}
	write(fd, "\n", 1);
}

//recursive bit
void	ft_find_routes(int fd, t_paths *head, t_paths *list, t_room *sroom)
{
	t_paths		*next;
	int			i;

	list->next = (t_paths*)ft_memalloc(sizeof(t_paths));
	i = 0;
	list->data = sroom->name;
	sroom->visited = 1;
	next = list->next;
	if (sroom->end == 1)
	{
		ft_createfile(head, fd);
	}
	while (sroom->roomlinks[i] && sroom->end == 0)
		{
			if (sroom->roomlinks[i]->visited == 0)
			{
				ft_find_routes(fd, head, next, sroom->roomlinks[i]);
			}
			i++;
		}
	list->data = NULL;
	free(next);
	list = NULL;
	sroom->visited = 0;
}

//calls recurive bit and saves to file, then goes on to read file into arrs
void	ft_checktunnels(t_args *args, t_vars *vars)
{
	t_paths	*list;
	int		fd;
	int		i;

	i = 0;
	list = (t_paths*)ft_memalloc(sizeof(t_paths));
	fd = open("links", O_TRUNC | O_RDWR | O_CREAT, 0666);

	ft_find_routes(fd, list, list, args->rooms[vars->start]);
	free(list);
	close(fd);
	fd = open("links", O_RDONLY);
	args->paths = (char***)ft_memalloc(sizeof(char**) * 10000);
	while (get_next_line(fd, &args->line))
	{
		args->paths[i] = ft_strsplit(args->line, ' ');
		free(args->line);
		i++;
	}
	close(fd);
}