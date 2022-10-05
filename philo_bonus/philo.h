/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:32:59 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 09:32:59 by ide-spir         ###   ########.fr       */
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
# include <semaphore.h>
# include <signal.h>
# include <stdatomic.h>

typedef struct s_dinner
{
	pthread_t		thread;
	int				philo_id;
	atomic_int		meal_count;
	atomic_long		time_last_meal;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	atomic_int		number_of_eat;
	long			start_time;
	sem_t			*sem_print;
	sem_t			*sem_forks;
	sem_t			*sem_dead;
	atomic_int		in_progress;
}				t_dinner;

//! check_arg.c
int		ft_check_arg(char *arg);

//! exit.c
int		ft_exit_with_message(char *message);

//! setup.c
int		ft_setup(int argc, char **argv, t_dinner *dinner);

//! philo.c
int		ft_play_philo(t_dinner *dinner);
void	ft_print_log(t_dinner *dinner, char *message);

//! time.c
long	ft_get_timestamp_in_ms(long start_time);
void	ft_sleep(unsigned long duration, t_dinner *dinner);

//! check_dead.c
void	ft_check_dead(t_dinner *dinner);

//! clear.c
void	ft_clear_dinner(t_dinner *dinner);

#endif
