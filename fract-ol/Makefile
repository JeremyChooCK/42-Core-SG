# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jechoo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 10:47:50 by jechoo            #+#    #+#              #
#    Updated: 2023/09/08 14:57:57 by jechoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SOURCES = \
	burningship.c burningship_utils.c ft_strcmp.c main.c mandelbrot.c mandelbrot_utils.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) ../../minilibx-linux/libmlx.a -lX11 -lXext -lm -lbsd

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
