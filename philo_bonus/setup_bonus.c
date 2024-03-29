/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:34:01 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 09:34:01 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_is_valid_args(int argc, t_dinner *dinner)
{
	if (dinner->number_of_philo < 1 || dinner->number_of_philo > 200)
		return (ft_exit_with_message("number of philosophers is invalid"));
	if (dinner->time_to_die < 60 || dinner->time_to_eat < 60
		|| dinner->time_to_sleep < 60)
		return (ft_exit_with_message("time argument is invalid"));
	if (argc == 6 && dinner->number_of_eat <= 0)
		return (ft_exit_with_message("number of eat is invalid"));
	return (1);
}

int	ft_setup_args(int argc, char **argv, t_dinner *dinner)
{
	if (argc != 5 && argc != 6)
		return (ft_exit_with_message("the number of arguments is invalid"));
	dinner->number_of_philo = ft_check_arg(argv[1]);
	dinner->time_to_die = ft_check_arg(argv[2]);
	dinner->time_to_eat = ft_check_arg(argv[3]);
	dinner->time_to_sleep = ft_check_arg(argv[4]);
	if (argc == 6)
		dinner->number_of_eat = ft_check_arg(argv[5]);
	else
		dinner->number_of_eat = 0;
	return (ft_is_valid_args(argc, dinner));
}

int	ft_setup_philo(t_dinner *dinner)
{
	dinner->meal_count = 0;
	dinner->time_last_meal = 0;
	dinner->in_progress = 1;
	return (1);
}

int	ft_setup_semaphores(t_dinner *dinner)
{
	sem_unlink("sem_print");
	sem_unlink("sem_forks");
	sem_unlink("sem_dead");
	dinner->sem_print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	if (dinner->sem_print == SEM_FAILED)
		exit(EXIT_FAILURE);
	dinner->sem_forks = sem_open("sem_forks", O_CREAT | O_EXCL, 0644,
			dinner->number_of_philo);
	if (dinner->sem_forks == SEM_FAILED)
		exit(EXIT_FAILURE);
	dinner->sem_dead = sem_open("sem_dead", O_CREAT | O_EXCL, 0644, 1);
	if (dinner->sem_dead == SEM_FAILED)
		exit(EXIT_FAILURE);
	return (1);
}

int	ft_setup(int argc, char **argv, t_dinner *dinner)
{
	if (!ft_setup_args(argc, argv, dinner))
		return (0);
	if (!ft_setup_philo(dinner))
		return (0);
	if (!ft_setup_semaphores(dinner))
		return (0);
	return (1);
}
