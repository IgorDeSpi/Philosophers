/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:34:32 by ide-spir          #+#    #+#             */
/*   Updated: 2022/08/29 16:08:22 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <time.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

struct	s_dinner;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				left_fork;
	int				right_fork;
	int				meal_count;
	long			time_last_meal;
	struct s_dinner	*dinner;
}				t_philo;

typedef struct s_dinner
{
	t_philo			*philo;
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_eat;
	long			start_time;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_dead;
	int				in_progress;
}				t_dinner;

int	check_arg(char *arg);

int	exit_with_message(char *message);
int	setup(int argc, char **argv, t_dinner *dinner);

int	play_philo(t_dinner *dinner);

long	get_timestamp_in_ms(long start_time);
void	ft_sleep(unsigned long duration, t_dinner *dinner);

void	print_log(t_philo *philo, char *message);
void	check_dead(t_dinner *dinner);

void	clear_dinner(t_dinner *dinner);

#endif
