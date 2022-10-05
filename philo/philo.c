/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:34:11 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 11:53:22 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_log(t_philo *philo, char *message)
{
	long	timestamp_in_ms;

	pthread_mutex_lock(&philo->dinner->mutex_print);
	if (philo->dinner->in_progress)
	{
		timestamp_in_ms = ft_get_timestamp_in_ms(philo->dinner->start_time);
		printf("%ld %d %s\n", timestamp_in_ms, philo->id, message);
	}
	pthread_mutex_unlock(&philo->dinner->mutex_print);
}

void	ft_philo_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner->mutex_forks[philo->left_fork]);
	ft_print_log(philo, "has taken a fork");
	pthread_mutex_lock(&philo->dinner->mutex_forks[philo->right_fork]);
	ft_print_log(philo, "has taken a fork");
	pthread_mutex_lock(&philo->dinner->mutex_dead);
	ft_print_log(philo, "is eating");
	philo->time_last_meal = ft_get_timestamp_in_ms(philo->dinner->start_time);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->dinner->mutex_dead);
	ft_sleep(philo->dinner->time_to_eat, philo->dinner);
	pthread_mutex_unlock(&philo->dinner->mutex_forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->dinner->mutex_forks[philo->right_fork]);
	ft_print_log(philo, "is sleeping");
	ft_sleep(philo->dinner->time_to_sleep, philo->dinner);
	ft_print_log(philo, "is thinking");
}

void	*ft_philo_life(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_sleep(50, philo->dinner);
	while (42)
	{
		pthread_mutex_lock(&philo->dinner->mutex_print);
		if (!philo->dinner->in_progress)
			break ;
		pthread_mutex_unlock(&philo->dinner->mutex_print);
		if (philo->dinner->nbr_of_philo > 1)
			ft_philo_loop(philo);
	}
	pthread_mutex_unlock(&philo->dinner->mutex_print);
	return (NULL);
}

int	ft_play_philo(t_dinner *dinner)
{
	int	i;

	i = 0;
	dinner->in_progress = 1;
	dinner->start_time = ft_get_timestamp_in_ms(0);
	while (i < dinner->nbr_of_philo)
	{
		dinner->philo[i].time_last_meal
			= ft_get_timestamp_in_ms(dinner->start_time);
		if (pthread_create(&dinner->philo[i].thread, NULL,
				(void *)ft_philo_life, &dinner->philo[i]))
			return (0);
		i++;
	}
	ft_check_dead(dinner);
	i = 0;
	while (i < dinner->nbr_of_philo)
	{
		pthread_join(dinner->philo[i].thread, NULL);
		i++;
	}
	return (1);
}
