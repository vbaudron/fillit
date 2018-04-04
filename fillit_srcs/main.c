/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:37:50 by cruiz             #+#    #+#             */
/*   Updated: 2017/02/02 17:29:27 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*map;
	size_t	nb;
	size_t	size;

	map = 0;
	nb = 0;
	size = 0;
	if (argc == 2)
	{
		map = ft_open(argv[1]);
		if (ft_is_valid_map(map) != 1 || ft_verif_tetri(map) != 1)
		{
			ft_putendl("error");
			return (0);
		}
		else
		{
			nb = ft_nb_tetri(map);
			size = ft_sizemin_square(nb);
			ft_algo_tabstruct(ft_crea_tabtetri(map), ft_crea_map(size), nb);
		}
	}
	else
		ft_putendl("usage: ./fillit file");
	return (0);
}
