/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:53:39 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/17 15:51:19 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int		count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count = 2;
	}
	while (n >= 10)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

static int	sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

char		*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	nbr = (char*)malloc(sizeof(*nbr) * size(n) + 1);
	if (nbr == NULL)
		return (NULL);
	i = size(n) - 1;
	nbr[i + 1] = '\0';
	if (n == -2147483648)
	{
		nbr[1] = '2';
		n = -147483648;
	}
	if (sign(n) < 0)
		nbr[0] = '-';
	if (n < 0)
		n *= -1;
	while (i > 0 && n >= 10)
	{
		nbr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	nbr[i] = n + '0';
	return (nbr);
}
