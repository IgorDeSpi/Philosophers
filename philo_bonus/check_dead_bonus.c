/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:33:23 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 09:33:23 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_check_is_starving(t_dinner *dinner)
{
	long	timestamp_in_ms;

	if (dinner->time_to_die < ft_get_timestamp_in_ms(dinner->start_time)
		- dinner->time_last_meal)
	{
		sem_wait(dinner->sem_print);
		timestamp_in_ms = ft_get_timestamp_in_ms(dinner->start_time);
		printf("%ld %d %s\n", timestamp_in_ms, dinner->philo_id, "died");
		exit(1);
	}
}

void	ft_check_is_dinner_end(t_dinner *dinner)
{
	if (dinner->meal_count > dinner->number_of_eat + 1)
	{
		sem_wait(dinner->sem_print);
		exit(1);
	}
}

void	ft_check_dead(t_dinner *dinner)
{
	int	i;

	while (dinner->in_progress)
	{
		i = 0;
		usleep(100);
		while (dinner->in_progress && i < dinner->number_of_philo)
		{
			sem_wait(dinner->sem_dead);
			ft_check_is_starving(dinner);
			sem_post(dinner->sem_dead);
			i++;
		}
		if (dinner->number_of_eat > 0)
		{
			sem_wait(dinner->sem_dead);
			ft_check_is_dinner_end(dinner);
			sem_post(dinner->sem_dead);
		}
	}
}
