#  ************************************************************************** #
#                                                           LE - /            #
#                                                               /             #
#    Makefile                                         .::    .:/ .      .::   #
#                                                  +:+:+   +:    +:  +:+:+    #
#    By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     #
#                                                  #+#   #+    #+    #+#      #
#    Created: 2019/06/24 16:19:43 by brey-gal     #+#   ##    ##    #+#       #
#    Updated: 2019/06/24 16:19:43 by brey-gal    ###    #+. /#+    ###.fr     #
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
		srcs/pan.c


OBJS = $(SRCS:.c=.o)

CFlAGS += -Wall -Werror -Wextra

LIB = -L. libft/libft.a

CC = CC

MLX = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) -C libft
		$(CC) -o $(NAME) $(OBJS) $(LIB) $(MLX)

clean :
		$(MAKE) clean -C libft
		rm -f $(OBJS)

fclean : clean
		$(MAKE) fclean -C libft
		rm -f $(NAME)

re : fclean all
