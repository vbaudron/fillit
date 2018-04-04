/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:19:51 by vbaudron          #+#    #+#             */
/*   Updated: 2017/01/31 12:53:21 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_free_struct(t_tetri **tetri, size_t nb_tetri)
{
	size_t i;

	i = 0;
	while (i < nb_tetri)
	{
		free(tetri[i]->diese1);
		free(tetri[i]->diese2);
		free(tetri[i]->diese3);
		free(tetri[i]->diese4);
		free(tetri[i]);
		i++;
	}
	free(tetri);
}
