/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:44:12 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/10 17:54:03 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	if (n == 0)
		return (s);
	n -= 1;
	while (n > 0)
	{
		((unsigned char*)s)[n] = (unsigned char)c;
		n--;
	}
	((unsigned char*)s)[n] = (unsigned char)c;
	return (s);
}
