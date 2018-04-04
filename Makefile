# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cruiz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 10:24:43 by cruiz             #+#    #+#              #
#    Updated: 2017/02/03 10:18:59 by cruiz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
PATH_LIB = ./libft_srcs/
PATH_FILLIT = ./fillit_srcs/
PATH_HEADERS = ./libft_srcs ./fillit_srcs/
HEADERS = libft.h fillit.h
SRC_LIB = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		  ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
		  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
		  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		  ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		  ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
		  ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
		  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
		  ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
		  ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
		  ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c

SRC_FILLIT = ft_is_valid_map.c ft_mv_tetri.c ft_nb_tetri.c \
			 ft_open.c ft_verif_tetri.c main.c ft_crea_map.c ft_sizemin_square.c \
			 ft_crea_tabtetri.c ft_algo_tabstruct.c ft_tetri_test.c \
			 ft_tabtetri_dup.c ft_free_struct.c ft_free_tpoint.c 

OBJ_LIB = $(SRC_LIB:.c=.o)
OBJ_FILLIT = $(SRC_FILLIT:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(addprefix $(PATH_LIB), $(SRC_LIB))
	ar rc $(LIB) $(OBJ_LIB)
	ranlib $(LIB)
	$(CC) $(FLAGS) -c $(addprefix $(PATH_FILLIT), $(SRC_FILLIT)) -Ilibft_srcs/ -Ifillit_srcs/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_FILLIT) -L. -lft

clean:
	rm -f $(OBJ_LIB) $(OBJ_FILLIT)

fclean: clean
	rm -f $(NAME) $(LIB)

re: fclean all
