/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:43:13 by cruiz             #+#    #+#             */
/*   Updated: 2017/01/17 11:20:56 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	*ft_open(char *file)
{
	int		fd;
	char	*map;
	char	buf[BUF_SIZE + 1];
	int		nb_max;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	nb_max = read(fd, buf, BUF_SIZE);
	if (nb_max > BUF_SIZE)
		return (0);
	map = malloc(sizeof(char) * nb_max + 1);
	if (map)
	{
		ft_strcpy(map, buf);
		map[nb_max] = '\0';
	}
	close(fd);
	return (map);
}
