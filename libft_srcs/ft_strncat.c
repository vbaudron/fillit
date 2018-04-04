/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:18:03 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/10 12:23:22 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (i < n && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	while (dest[dest_len + i])
	{
		dest[dest_len + i] = '\0';
		i++;
	}
	return (dest);
}
