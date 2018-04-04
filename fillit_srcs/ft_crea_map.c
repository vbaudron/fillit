/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crea_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:00:13 by cruiz             #+#    #+#             */
/*   Updated: 2017/02/02 15:20:24 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	*ft_crea_map(size_t size)
{
	char	*map;
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	if (!(map = malloc(sizeof(char) * (size + 1) * size + 1)))
		return (0);
	while (i < (size + 1) * size && j <= size)
	{
		while (i < (size + 1) * j - 1)
		{
			map[i] = '.';
			i++;
		}
		map[i] = '\n';
		i++;
		j++;
	}
	map[i] = '\0';
	return (map);
}
