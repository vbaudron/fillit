/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crea_tabtetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:45:36 by vbaudron          #+#    #+#             */
/*   Updated: 2017/02/02 17:17:25 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	int		ft_fulltab_diese(char *tab, t_point **diese, size_t i, int d)
{
	int y;

	y = 0;
	while (d < 4)
	{
		while (tab[i] == '.')
			i++;
		if (tab[i] == '\n')
		{
			y++;
			i++;
		}
		if (tab[i] == '#')
		{
			diese[d]->x = i - (y * 5);
			diese[d]->y = y;
			d++;
			i++;
		}
	}
	return (1);
}

static	int		ft_fulltetri(t_point **diese, t_tetri *tetri)
{
	if ((tetri->diese1 = malloc(sizeof(t_point))) != 0)
	{
		tetri->diese1->x = diese[0]->x;
		tetri->diese1->y = diese[0]->y;
	}
	if ((tetri->diese2 = malloc(sizeof(t_point))) != 0)
	{
		tetri->diese2->x = diese[1]->x;
		tetri->diese2->y = diese[1]->y;
	}
	if ((tetri->diese3 = malloc(sizeof(t_point))) != 0)
	{
		tetri->diese3->x = diese[2]->x;
		tetri->diese3->y = diese[2]->y;
	}
	if ((tetri->diese4 = malloc(sizeof(t_point))) != 0)
	{
		tetri->diese4->x = diese[3]->x;
		tetri->diese4->y = diese[3]->y;
	}
	return (0);
}

static char		*ft_cpy_tetri(char *dst, char *map, size_t i)
{
	size_t	j;

	j = 0;
	while (j < 20)
	{
		dst[j] = map[i + j];
		j++;
	}
	dst[j] = '\0';
	dst = ft_mv_tetri(dst);
	return (dst);
}

static t_tetri	*ft_crea_tetri(t_tetri *tetri, char *map, size_t i, char letter)
{
	char	*tab;
	t_point	**diese;
	size_t	j;

	j = 0;
	if ((diese = malloc(sizeof(t_point*) * 4)) == 0)
		return (0);
	if ((tab = malloc(sizeof(char) * 21)) == 0)
		return (0);
	while (j < 4)
	{
		if ((diese[j] = malloc(sizeof(t_point))) == 0)
			return (0);
		j++;
	}
	tab = ft_cpy_tetri(tab, map, i);
	if ((tetri = malloc(sizeof(t_tetri))) == 0)
		return (0);
	tetri->letter = letter;
	tetri->pos = 0;
	ft_fulltab_diese(tab, diese, 0, 0);
	ft_fulltetri(diese, tetri);
	free(tab);
	ft_free_tpoint(diese, 4);
	return (tetri);
}

t_tetri			**ft_crea_tabtetri(char *map)
{
	size_t	i;
	size_t	j;
	char	letter;
	t_tetri	**tetri;

	i = 0;
	j = 0;
	letter = 'A';
	tetri = malloc(sizeof(t_tetri*) * ft_nb_tetri(map));
	if (!tetri)
		return (0);
	while (i < ft_strlen(map))
	{
		tetri[j] = ft_crea_tetri(tetri[j], map, i, letter);
		i += 21;
		letter++;
		j++;
	}
	return (tetri);
}
