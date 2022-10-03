/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:46:46 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/03 22:55:03 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_timestamp_in_ms(long start_time)
{
	struct timeval	time;
	long			time_stamp_in_ms;

	gettimeofday(&time, NULL);
	time_stamp_in_ms = (time.tv_sec * 1000) \
		+ (time.tv_usec) / 1000 - start_time;
	return (time_stamp_in_ms);
}

void	ft_sleep(unsigned long duration, t_dinner *dinner)
{
	unsigned long	start;

	start = ft_get_timestamp_in_ms(0);
	while (42)
	{
		if (ft_get_timestamp_in_ms(0) - start >= duration)
			break ;
		sem_wait(dinner->sem_print);
		if (!dinner->in_progress)
		{
			sem_post(dinner->sem_print);
			break ;
		}
		sem_post(dinner->sem_print);
		usleep(100);
	}
}
