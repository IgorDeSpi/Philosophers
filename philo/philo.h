/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:34:32 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 11:45:11 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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

//! check_arg.c
int		ft_check_arg(char *arg);

//! exit.c
int		ft_exit_with_message(char *message);

//! setup.c
int		ft_setup(int argc, char **argv, t_dinner *dinner);

//! philo.c
void	ft_print_log(t_philo *philo, char *message);
int		ft_play_philo(t_dinner *dinner);

//! time.c
long	ft_get_timestamp_in_ms(long start_time);
void	ft_sleep(unsigned long duration, t_dinner *dinner);

//! check_dead.c
void	ft_check_dead(t_dinner *dinner);

//! clear.c
void	ft_clear_dinner(t_dinner *dinner);

#endif
