/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:11:56 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/17 17:47:30 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && i < j)
		j--;
	res = (char*)malloc(sizeof(*res) * (j - i) + 2);
	if (res == NULL)
		return (NULL);
	while (i <= j)
	{
		res[k] = s[i];
		i++;
		k++;
	}
	res[k] = '\0';
	return (res);
}
