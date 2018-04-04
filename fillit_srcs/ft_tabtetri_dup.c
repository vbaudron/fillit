/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtetri_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:48:14 by vbaudron          #+#    #+#             */
/*   Updated: 2017/02/02 15:36:25 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_tetri	*ft_cp_tpoint(t_tetri *dst, t_tetri *src)
{
	if ((dst->diese1 = malloc(sizeof(t_point))) != 0)
	{
		dst->diese1->x = src->diese1->x;
		dst->diese1->y = src->diese1->y;
	}
	if ((dst->diese2 = malloc(sizeof(t_point))) != 0)
	{
		dst->diese2->x = src->diese2->x;
		dst->diese2->y = src->diese2->y;
	}
	if ((dst->diese3 = malloc(sizeof(t_point))) != 0)
	{
		dst->diese3->x = src->diese3->x;
		dst->diese3->y = src->diese3->y;
	}
	if ((dst->diese4 = malloc(sizeof(t_point))) != 0)
	{
		dst->diese4->x = src->diese4->x;
		dst->diese4->y = src->diese4->y;
		return (dst);
	}
	return (0);
}

t_tetri	**ft_tabtetri_dup(t_tetri **tab_tetri, size_t nb_tetri)
{
	t_tetri **tab_new;
	size_t	i;

	i = 0;
	if ((tab_new = malloc(sizeof(t_tetri*) * nb_tetri)) != 0)
	{
		while (i < nb_tetri)
		{
			if ((tab_new[i] = malloc(sizeof(t_tetri))) != 0)
			{
				tab_new[i]->letter = tab_tetri[i]->letter;
				ft_cp_tpoint(tab_new[i], tab_tetri[i]);
			}
			i++;
		}
	}
	return (tab_new);
}
