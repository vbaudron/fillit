/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:12:43 by cruiz             #+#    #+#             */
/*   Updated: 2017/01/17 11:21:30 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		ft_one_tetri(char *map, size_t i)
{
	size_t	link;
	size_t	diese;

	link = 0;
	diese = 0;
	while (diese < 4 && i < ft_strlen(map) - 1)
	{
		if (map[i] != '#')
			i++;
		if (map[i] == '#')
		{
			diese++;
			if (map[i + 1] == '#')
				link++;
			if (map[i + 5] == '#')
				link++;
			i++;
		}
	}
	if (link < 3 && diese == 4)
		return (0);
	return (i);
}

int				ft_verif_tetri(char *map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map) - 1)
	{
		if (ft_one_tetri(map, i) == 0)
			return (0);
		i = i + ft_one_tetri(map, i);
	}
	return (1);
}
