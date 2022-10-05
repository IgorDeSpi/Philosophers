/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:57:12 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 11:41:36 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clear_dinner(t_dinner *dinner)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&dinner->mutex_print);
	pthread_mutex_destroy(&dinner->mutex_dead);
	while (i < dinner->nbr_of_philo)
	{
		pthread_mutex_destroy(dinner->mutex_forks + i);
		i++;
	}
	free(dinner->philo);
	free(dinner->mutex_forks);
}
