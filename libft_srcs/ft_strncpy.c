/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:41:34 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/10 14:10:06 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i] && i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
