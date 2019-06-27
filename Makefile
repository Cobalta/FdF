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

SRCS =	srcs/fdf.c 			\
		srcs/ft_win_del.c	\
		srcs/line_tracer.c

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
