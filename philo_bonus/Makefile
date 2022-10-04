SRCS = main.c setup.c check_arg.c exit.c philo.c check_dead.c time.c clear.c
OBJS = $(SRCS:.c=.o)
NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -pthread

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
