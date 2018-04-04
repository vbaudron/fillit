/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:55:46 by cruiz             #+#    #+#             */
/*   Updated: 2017/02/02 15:29:51 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int	ft_verif_char(char *map, size_t i, int line, int diese)
{
	int		column;

	column = 0;
	while ((map[i] == '.' || map[i] == '#') && line < 4)
	{
		if (map[i] == '#')
			diese++;
		i++;
		column++;
		if (map[i] == '\n')
		{
			if (column == 4)
			{
				i++;
				column = 0;
				line++;
			}
			else
				return (0);
		}
	}
	if (line == 4 && column == 0 && diese == 4)
		return (i);
	return (0);
}

int			ft_is_valid_map(char *map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map))
	{
		if (ft_verif_char(map, i, 0, 0) != 0)
		{
			i = ft_verif_char(map, i, 0, 0);
			if (map[i - 1] == '\n' && !map[i])
				return (1);
			if (!map[i])
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (0);
}
