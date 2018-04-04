/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:17:07 by vbaudron          #+#    #+#             */
/*   Updated: 2017/02/02 17:25:34 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	ft_tetritest2(t_tetri *tetri, char *map, size_t size, size_t i)
{
	int		ret;
	size_t	pos;

	ret = 1;
	pos = (tetri->diese3->x + i) + (tetri->diese3->y * (size + 1));
	if (map[pos] != '.' || pos > (size) * (size + 1))
		ret = 0;
	if (ret == 1)
	{
		pos = (tetri->diese4->x + i) + (tetri->diese4->y * (size + 1));
		if (map[pos] != '.' || pos > (size) * (size + 1))
			ret = 0;
	}
	return (ret);
}

int			ft_tetri_test(t_tetri *tetri, char *map, size_t size, size_t i)
{
	int		ret;
	size_t	pos;

	ret = 1;
	pos = (tetri->diese1->x + i) + (tetri->diese1->y * (size + 1));
	if (map[pos] != '.' || pos > (size) * (size + 1))
		ret = 0;
	if (ret == 1)
	{
		pos = (tetri->diese2->x + i) + (tetri->diese2->y * (size + 1));
		if (map[pos] != '.' || pos > (size) * (size + 1))
			ret = 0;
		else
			ret = ft_tetritest2(tetri, map, size, i);
	}
	if (ret == 0)
	{
		if (pos + 1 < size * (size + 1))
			return (ft_tetri_test(tetri, map, size, i + 1));
		return (-1);
	}
	return ((int)i);
}
