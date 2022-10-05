/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:33:56 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 09:33:56 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_log(t_dinner *dinner, char *message)
{
	long	timestamp_in_ms;

	sem_wait(dinner->sem_print);
	if (dinner->in_progress)
	{
		timestamp_in_ms = ft_get_timestamp_in_ms(dinner->start_time);
		printf("%ld %d %s\n", timestamp_in_ms, dinner->philo_id, message);
	}
	sem_post(dinner->sem_print);
}

void	philo_loop(t_dinner *dinner)
{
	sem_wait(dinner->sem_forks);
	ft_print_log(dinner, "has taken a fork");
	sem_wait(dinner->sem_forks);
	ft_print_log(dinner, "has taken a fork");
	sem_wait(dinner->sem_dead);
	ft_print_log(dinner, "is eating");
	dinner->time_last_meal = (int)ft_get_timestamp_in_ms(dinner->start_time);
	dinner->meal_count++;
	sem_post(dinner->sem_dead);
	ft_sleep(dinner->time_to_eat, dinner);
	sem_post(dinner->sem_forks);
	sem_post(dinner->sem_forks);
	ft_print_log(dinner, "is sleeping");
	ft_sleep(dinner->time_to_sleep, dinner);
	ft_print_log(dinner, "is thinking");
}

void	*philo_life(t_dinner *dinner)
{
	if (dinner->philo_id % 2 == 0)
		ft_sleep(50, dinner);
	if (pthread_create(&dinner->thread, NULL, (void *)ft_check_dead, dinner))
		return (0);
	while (42)
	{
		sem_wait(dinner->sem_print);
		if (!dinner->in_progress)
			break ;
		sem_post(dinner->sem_print);
		if (dinner->number_of_philo > 1)
			philo_loop(dinner);
	}
	sem_post(dinner->sem_print);
	exit(0);
	return (NULL);
}

int	ft_play_philo(t_dinner *dinner)
{
	int	i;
	int	*pid;

	i = 0;
	pid = malloc(sizeof(int) * dinner->number_of_philo);
	if (!pid)
		exit(1);
	dinner->start_time = ft_get_timestamp_in_ms(0);
	dinner->time_last_meal = ft_get_timestamp_in_ms(dinner->start_time);
	while (i < dinner->number_of_philo)
	{
		dinner->philo_id = i + 1;
		pid[i] = fork();
		if (pid[i] == 0)
			philo_life(dinner);
		i++;
	}
	waitpid(-1, NULL, 0);
	i = -1;
	while (++i < dinner->number_of_philo)
		kill(pid[i], SIGKILL);
	free(pid);
	return (1);
}
