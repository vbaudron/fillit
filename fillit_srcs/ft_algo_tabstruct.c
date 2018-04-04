/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_tabstruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:45:25 by vbaudron          #+#    #+#             */
/*   Updated: 2017/02/02 17:28:21 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static size_t	ft_tetricpy(t_tetri *tetri, char *map, size_t size, size_t i)
{
	size_t pos;

	pos = (tetri->diese1->x + i) + (tetri->diese1->y * (size + 1));
	map[pos] = tetri->letter;
	pos = (tetri->diese2->x + i) + (tetri->diese2->y * (size + 1));
	map[pos] = tetri->letter;
	pos = (tetri->diese3->x + i) + (tetri->diese3->y * (size + 1));
	map[pos] = tetri->letter;
	pos = (tetri->diese4->x + i) + (tetri->diese4->y * (size + 1));
	map[pos] = tetri->letter;
	return (i);
}

static int		ft_clean_tetri(t_tetri *tetri, char *map, size_t size, size_t i)
{
	size_t pos;

	pos = (tetri->diese1->x + i) + (tetri->diese1->y * (size + 1));
	map[pos] = '.';
	pos = (tetri->diese2->x + i) + (tetri->diese2->y * (size + 1));
	map[pos] = '.';
	pos = (tetri->diese3->x + i) + (tetri->diese3->y * (size + 1));
	map[pos] = '.';
	pos = (tetri->diese4->x + i) + (tetri->diese4->y * (size + 1));
	map[pos] = '.';
	return (i);
}

static	int		ft_non_insert(t_tetri **tab, char *map, size_t size, size_t j)
{
	if (j < 1)
		return (-1);
	j--;
	ft_clean_tetri(tab[j], map, size, tab[j]->pos);
	return ((int)j);
}

static char		*ft_insert(t_tetri **tab, char *map, size_t j, size_t nb)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (map[size] != '\n')
		size++;
	while (j < nb)
	{
		if ((tab[j]->pos = ft_tetri_test(tab[j], map, size, i)) != -1)
		{
			ft_tetricpy(tab[j], map, size, tab[j]->pos);
			j++;
			i = 0;
			if (j == nb)
				return (map);
		}
		else
		{
			if ((j = ft_non_insert(tab, map, size, j)) == -1)
				return (0);
			i = tab[j]->pos + 1;
		}
	}
	return (0);
}

int				ft_algo_tabstruct(t_tetri **tab, char *map, size_t nb)
{
	size_t	size;
	t_tetri	**tab_save;
	size_t	i;

	i = 0;
	size = ft_sizemin_square(nb);
	tab_save = ft_tabtetri_dup(tab, nb);
	while ((map = ft_insert(tab, map, 0, nb)) == 0 && size <= nb * 4)
	{
		ft_free_struct(tab, nb);
		tab = ft_tabtetri_dup(tab_save, nb);
		size++;
		free(map);
		map = ft_crea_map(size);
	}
	ft_free_struct(tab, nb);
	ft_putstr(map);
	return (1);
}
