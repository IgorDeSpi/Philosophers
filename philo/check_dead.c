/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:35:32 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 11:41:36 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_is_starving(t_dinner *dinner, t_philo *philo)
{
	long	timestamp_in_ms;

	if (dinner->time_to_die < ft_get_timestamp_in_ms(dinner->start_time)
		- philo->time_last_meal)
	{
		pthread_mutex_lock(&dinner->mutex_print);
		timestamp_in_ms = ft_get_timestamp_in_ms(philo->dinner->start_time);
		printf("%ld %d %s\n", timestamp_in_ms, philo->id, "died");
		dinner->in_progress = 0;
		pthread_mutex_unlock(&dinner->mutex_print);
	}
}

void	check_is_dinner_end(t_dinner *dinner)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < dinner->nbr_of_philo)
	{
		philo = dinner->philo[i];
		if (philo.meal_count < dinner->nbr_of_eat)
			return ;
		i++;
	}
	pthread_mutex_lock(&dinner->mutex_print);
	dinner->in_progress = 0;
	pthread_mutex_unlock(&dinner->mutex_print);
}

void	ft_check_dead(t_dinner *dinner)
{
	int	i;

	while (dinner->in_progress)
	{
		i = 0;
		usleep(100);
		while (dinner->in_progress && i < dinner->nbr_of_philo)
		{
			pthread_mutex_lock(&dinner->mutex_dead);
			check_is_starving(dinner, &dinner->philo[i]);
			pthread_mutex_unlock(&dinner->mutex_dead);
			i++;
		}
		if (dinner->nbr_of_eat > 0)
		{
			pthread_mutex_lock(&dinner->mutex_dead);
			check_is_dinner_end(dinner);
			pthread_mutex_unlock(&dinner->mutex_dead);
		}
	}
}
