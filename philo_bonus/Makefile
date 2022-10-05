# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 09:33:49 by ide-spir          #+#    #+#              #
#    Updated: 2022/10/05 09:33:49 by ide-spir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main_bonus.c \
		setup_bonus.c \
		check_arg_bonus.c \
		exit_bonus.c \
		philo_bonus.c \
		check_dead_bonus.c \
		time_bonus.c \
		clear_bonus.c

OBJS = $(SRCS:.c=.o)

NAME = philo_bonus

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
