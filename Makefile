# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboit <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 12:57:40 by lboit             #+#    #+#              #
#    Updated: 2019/03/25 15:52:35 by lboit            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS ?= -Wall -Wextra -Werror -g3 
CPPFLAGS = -I ./libft/

NAME = fillit

LIB = libft/libft.a

SRCS = main.c \
	   check.c \
	   map.c \
	   move.c \
	   read.c \
	   resolve.c \
	   ft_strjoinfree.c \
	   tet_ok.c

all: $(NAME)

OBJS = $(SRCS:.c=.o)

$(LIB):
	make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(LIB) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
		make clean -C libft/
		rm -f $(OBJS)

fclean: clean
		make fclean -C libft/
		rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
