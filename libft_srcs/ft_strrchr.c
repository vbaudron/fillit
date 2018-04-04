/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:46:03 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/10 13:50:47 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = ft_strlen(s);
	while (i > 0 && s[i] != c)
		i--;
	if (s[i] == c)
	{
		res = (char*)&s[i];
		return (res);
	}
	else
		return (NULL);
}
