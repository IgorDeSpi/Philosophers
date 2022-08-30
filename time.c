/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:20:13 by ide-spir          #+#    #+#             */
/*   Updated: 2022/08/30 10:28:22 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_timestamp_in_ms(long start_time)
{
	struct timeval	time;
	long			timestamp_in_ms;

	gettimeofday(&time, NULL);
	timestamp_in_ms = (time.tv_sec * 1000) + (time.tv_usec) / 1000 - start_time;
	return (timestamp_in_ms);
}

void	ft_sleep(unsigned long duration, t_dinner *dinner)
{
	unsigned long	start;

	start = get_timestamp_in_ms(0);
	while (42)
	{
		if (get_timestamp_in_ms(0) - start >= duration)
			break ;
		pthread_mutex_lock(&dinner->mutex_print);
		if (!dinner->in_progress)
		{
			pthread_mutex_unlock(&dinner->mutex_print);
			break ;
		}
		pthread_mutex_unlock(&dinner->mutex_print);
		usleep(100);
	}
}
