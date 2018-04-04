/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizemin_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:26:36 by cruiz             #+#    #+#             */
/*   Updated: 2017/01/17 13:13:11 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

size_t	ft_sizemin_square(size_t nb_tetri)
{
	size_t	i;

	i = 1;
	while (i * i < 4 * nb_tetri)
		i++;
	return (i);
}
