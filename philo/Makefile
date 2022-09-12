# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 15:34:47 by ide-spir          #+#    #+#              #
#    Updated: 2022/09/12 16:33:06 by ide-spir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = check_arg.c \
		check_dead.c \
		clear.c \
		exit.c \
		main.c \
		philosophers.c \
		setup.c \
		time.c

OBJS = $(SRCS:.c=.o)

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ -pthread

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
