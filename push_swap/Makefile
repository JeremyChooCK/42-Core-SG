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

NAME = push_swap
SOURCES = \
	checkerror.c ft_atoi.c ft_split.c ft_strlen.c issorted.c printerror.c push.c push_swap.c quicksort.c reverserotate.c rotate.c sort3.c sort4.c sort5.c sortmorethan5.c swap.c throwtoa.c  throwtob.c throwtob_utils.c throwtob_utils2.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
