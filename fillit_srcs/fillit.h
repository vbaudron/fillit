/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:08:52 by cruiz             #+#    #+#             */
/*   Updated: 2017/02/03 10:09:43 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 545
# include <fcntl.h>

typedef	struct	s_point
{
	int x;
	int y;
}				t_point;

typedef	struct	s_tetri
{
	char	letter;
	t_point	*diese1;
	t_point	*diese2;
	t_point *diese3;
	t_point *diese4;
	int		pos;
}				t_tetri;

int				ft_algo_tabstruct(t_tetri **tab, char *map, size_t nb);
t_tetri			**ft_crea_tabtetri(char *map);
int				ft_tetri_test(t_tetri *tetri, char *map, size_t size, size_t i);
void			ft_free_struct(t_tetri **tetri, size_t nb_tetri);
void			ft_swap_tetri(t_tetri *s1, t_tetri *s2);
t_tetri			**ft_tabtetri_dup(t_tetri **tab_tetri, size_t nb_tetri);
void			ft_free_tpoint(t_point **diese, size_t len);
int				ft_is_valid_map(char *file);
int				ft_verif_tetri(char *map);
char			*ft_open(char *file);
size_t			ft_nb_tetri(char *map);
char			*ft_mv_tetri(char *tetri);
char			*ft_crea_map(size_t size);
size_t			ft_sizemin_square(size_t nb_tetri);

#endif
