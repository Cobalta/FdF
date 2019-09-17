#  ************************************************************************** #
#                                                           LE - /            #
#                                                               /             #
#    Makefile                                         .::    .:/ .      .::   #
#                                                  +:+:+   +:    +:  +:+:+    #
#    By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     #
#                                                  #+#   #+    #+    #+#      #
#    Created: 2019/06/24 16:19:43 by brey-gal     #+#   ##    ##    #+#       #
#    Updated: 2019/07/21 23:28:23 by brey-gal    ###    #+. /#+    ###.fr      #
#                                                          /                  #
#                                                         /                   #
#  ************************************************************************** #

NAME = fdf

SRCS =	srcs/main.c 			\
		srcs/struct_del.c		\
		srcs/line_tracer.c		\
		srcs/get_next_line.c	\
		srcs/fdf.c				\
		srcs/get_map.c			\
		srcs/struct_new.c		\
		srcs/struct_next.c	    \
		srcs/render.c           \
		srcs/matrix_op.c        \
		srcs/setup.c            \
		srcs/map_to_struct.c	\
		srcs/vec_op.c           \
		srcs/fill_pixel.c		\
		srcs/get_gradient.c		\
		srcs/menu.c				\
		srcs/displaymenu.c		\
		srcs/pan.c				\
		srcs/operation.c

LIBSRC =	libft/ft_puterror.c 	\
       		libft/ft_putstr.c		\
			libft/ft_strnew.c		\
			libft/ft_strjoin.c		\
			libft/ft_strcpy.c		\
			libft/ft_strsub.c		\
			libft/ft_strlen.c		\
			libft/ft_strdup.c		\
			libft/ft_atoi.c			\
			libft/ft_itoa.c

INC =	includes/fdf.h	\
		includes/struct.h

OBJS =	$(SRCS:.c=.o) 	\
		$(LIBSRC:.c=.o)

CFlAGS += -Wall -Werror -Wextra

LIB = -L. libft/libft.a

CC = CC

MLX = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
		$(MAKE) -C libft
		$(MAKE) -C minilibx
		$(CC) -o $(NAME) $(OBJS) $(LIB) $(MLX)

clean :
		$(MAKE) clean -C libft
		rm -f $(OBJS)

fclean : clean
		$(MAKE) fclean -C libft
		$(MAKE) clean -C minilibx
		rm -f $(NAME)

re : fclean all
