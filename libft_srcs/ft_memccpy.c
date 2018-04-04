/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:09:32 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/18 17:35:08 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n - 1 && ((unsigned char*)src)[i] != (unsigned char)c)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
	if (((unsigned char*)dest)[i] == (unsigned char)c)
		return (&((unsigned char*)dest)[i + 1]);
	else
		return (NULL);
}
