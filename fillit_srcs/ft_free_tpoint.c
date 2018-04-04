/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tpoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:58:12 by vbaudron          #+#    #+#             */
/*   Updated: 2017/01/31 10:05:47 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_free_tpoint(t_point **diese, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		free(diese[i]);
		i++;
	}
}
