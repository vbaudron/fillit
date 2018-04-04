/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:03:47 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/11 12:00:25 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (n == 0)
		return (dest);
	n -= 1;
	while (n > 0)
	{
		((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
		n--;
	}
	((unsigned char*)dest)[0] = ((unsigned char*)src)[0];
	return (dest);
}
