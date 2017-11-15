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

//saves the routes to a file to be read into 3d arrs
void	ft_createfile(t_list *head, int fd)
{
	while (head && head->data)
	{
		write(fd, head->data, ft_strlen(head->data));
		write(fd, ' ', 1);
		head = head->next;
	}
	ft_putchar('\n');
}

//recursive bit
void	ft_find_routes(int fd, t_list *head, t_list *paths, t_room *roomlinks)
{

}

//calls recurive bit and saves to file, then goes on to read file into arrs
void	ft_checktunnels(t_args *args, t_vars *vars)
{
	t_list	*list;
	int		fd;
	int		i;

	list = (char***)ft_memalloc(sizeof(char**));
fd = open("");
}