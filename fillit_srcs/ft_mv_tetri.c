/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:50:47 by cruiz             #+#    #+#             */
/*   Updated: 2017/02/02 15:30:23 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	*ft_mv_line(char *new)
{
	size_t	i;
	size_t	line;

	i = 0;
	line = 0;
	while (new[line] == '.' && line < 20)
		line += 5;
	if (line == 20)
	{
		while (new[i])
		{
			if (new[i] != '.' && new[i] != '\n')
			{
				new[i - 1] = new[i];
				new[i] = '.';
			}
			i++;
		}
	}
	return (new);
}

char	*ft_mv_column(char *new)
{
	size_t	i;
	size_t	column;

	i = 0;
	column = 0;
	while (new[column] == '.' && column < 4)
		column++;
	if (column == 4)
	{
		while (new[i])
		{
			if (new[i] != '.' && new[i] != '\n')
			{
				new[i - 5] = new[i];
				new[i] = '.';
			}
			i++;
		}
	}
	return (new);
}

char	*ft_mv_tetri(char *tetri)
{
	size_t	column;
	size_t	line;
	size_t	count;
	char	*new;

	line = 0;
	column = 0;
	count = 0;
	new = malloc(sizeof(char) * 21);
	if (!new)
		return (0);
	new = ft_strcpy(new, tetri);
	while (count < 3)
	{
		new = ft_mv_line(new);
		new = ft_mv_column(new);
		count++;
	}
	return (new);
}
