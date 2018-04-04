/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:31:01 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/17 16:54:47 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (s == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(*res) * len + 1);
	if (res == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[len] = '\0';
	return (res);
}
