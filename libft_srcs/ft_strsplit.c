/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:27:15 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/18 15:47:59 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	sizeof_res(char *s, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static size_t	sizeof_new_str(char *s, char c, size_t start)
{
	size_t		count;

	count = 0;
	while (s[start] == c && s[start])
		start++;
	while (s[start] != c && s[start])
	{
		start++;
		count++;
	}
	return (count);
}

static char		*new_str(char const *s, size_t start, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)ft_strnew(size);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	if (c == 0)
		return ((char**)s);
	i = 0;
	j = 0;
	if (!(res = (char**)malloc(sizeof(char*) * sizeof_res((char*)s, c) + 1)))
		return (NULL);
	while (i < sizeof_res((char*)s, c) && s[j])
	{
		while (s[j] == c && s[j])
			j++;
		if (s[j] != c && s[j])
		{
			res[i] = new_str((char*)s, j, sizeof_new_str((char*)s, c, j));
			j += sizeof_new_str((char*)s, c, j);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
