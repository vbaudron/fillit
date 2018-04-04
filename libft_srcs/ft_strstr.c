/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:55:13 by cruiz             #+#    #+#             */
/*   Updated: 2016/12/03 12:12:28 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if ((*src == '\0' && *to_find == '\0') || *to_find == '\0')
		return ((char*)src);
	while (src[i])
	{
		j = 0;
		while (src[i] && src[i] != to_find[j])
			i++;
		k = i;
		if (!src[i])
			return (NULL);
		while (src[i + 1] && to_find[j + 1] && src[i] == to_find[j])
		{
			i++;
			j++;
		}
		if (src[i] == to_find[j] && to_find[j + 1] == '\0')
			return (&((char*)src)[k]);
		i = k + 1;
	}
	return (NULL);
}
