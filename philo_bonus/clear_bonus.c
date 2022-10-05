/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:33:30 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 09:33:30 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_clear_dinner(t_dinner *dinner)
{
	sem_close(dinner->sem_print);
	sem_close(dinner->sem_dead);
	sem_close(dinner->sem_forks);
	sem_unlink("sem_print");
	sem_unlink("sem_forks");
	sem_unlink("sem_dead");
}
