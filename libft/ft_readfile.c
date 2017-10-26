/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:43:31 by kroutled          #+#    #+#             */
/*   Updated: 2017/10/26 13:22:15 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile(int fd)
{
	char	*file;
	char	*temp;
	char	*another;

	temp = (char*)malloc(sizeof(char));
	while (get_next_line(fd, &file))
	{
		another = ft_strjoin(temp, file);
		free(temp);
		temp = ft_strjoin(another, "\n");
		free(another);
		free(file);
	}
	return (temp);
}
