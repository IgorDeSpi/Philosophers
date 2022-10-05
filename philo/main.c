/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:34:21 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 11:44:11 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dinner	dinner;

	if (!ft_setup(argc, argv, &dinner))
		return (1);
	ft_play_philo(&dinner);
	ft_clear_dinner(&dinner);
	return (0);
}
