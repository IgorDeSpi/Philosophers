/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:46:15 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/06 09:20:03 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_valid_args(int argc, t_dinner *dinner)
{
	if (dinner->nbr_of_philo < 1 || dinner->nbr_of_philo > 200)
		return (ft_exit_with_message("Number of philosophers is invalid"));
	if (dinner->time_to_die < 60 || dinner->time_to_eat < 60
		|| dinner->time_to_sleep < 60)
		return (ft_exit_with_message("Time argument is not valid"));
	if (argc == 6 && dinner->nbr_of_eat <= 0)
		return (ft_exit_with_message("Number of eat is invalid"));
	return (1);
}

int	ft_setup_args(int argc, char **argv, t_dinner *dinner)
{
	if (argc != 5 && argc != 6)
		return (ft_exit_with_message("The number of arguments is not valid"));
	dinner->nbr_of_philo = ft_check_arg(argv[1]);
	dinner->time_to_die = ft_check_arg(argv[2]);
	dinner->time_to_eat = ft_check_arg(argv[3]);
	dinner->time_to_sleep = ft_check_arg(argv[4]);
	if (argc == 6)
		dinner->nbr_of_eat = ft_check_arg(argv[5]);
	else
		dinner->nbr_of_eat = 0;
	return (ft_is_valid_args(argc, dinner));
}

int	ft_setup_philo(t_dinner *dinner)
{
	int	i;

	dinner->philo = malloc(sizeof(t_philo) * dinner->nbr_of_philo);
	if (!dinner->philo)
		return (0);
	i = 0;
	while (i < dinner->nbr_of_philo)
	{
		dinner->philo[i].id = i + 1;
		dinner->philo[i].left_fork = i;
		dinner->philo[i].right_fork = (i + 1) % dinner->nbr_of_philo;
		dinner->philo[i].meal_count = 0;
		dinner->philo[i].dinner = dinner;
		i++;
	}
	return (1);
}

int	ft_setup_mutex(t_dinner *dinner)
{
	int	i;

	if (pthread_mutex_init(&dinner->mutex_print, NULL) != 0)
		return (0);
	dinner->mutex_forks = malloc(sizeof(pthread_mutex_t)
			* dinner->nbr_of_philo);
	if (!dinner->mutex_forks)
		return (0);
	i = 0;
	while (i < dinner->nbr_of_philo)
	{
		if (pthread_mutex_init(&dinner->mutex_forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&dinner->mutex_dead, NULL) != 0)
		return (0);
	return (1);
}

int	ft_setup(int argc, char **argv, t_dinner *dinner)
{
	if (!ft_setup_args(argc, argv, dinner))
		return (0);
	if (!ft_setup_philo(dinner))
		return (0);
	if (!ft_setup_mutex(dinner))
		return (0);
	return (1);
}
