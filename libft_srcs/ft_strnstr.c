/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:37:22 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/22 14:10:03 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*to_find == '\0')
		return ((char*)src);
	if (ft_strlen(src) < ft_strlen(to_find))
		return (0);
	while (src[i])
	{
		j = 0;
		while (src[i] != to_find[j] && i < n)
			i++;
		if (src[i] != to_find[j] || !src[i] || n - i < ft_strlen(to_find))
			return (NULL);
		while (src[i + 1] && to_find[j + 1] && src[i] == to_find[j])
		{
			i++;
			j++;
		}
		if (src[i] == to_find[j])
			return (&((char*)src)[i - j]);
		i = i - j + 1;
	}
	return (NULL);
}
