/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:34:21 by ide-spir          #+#    #+#             */
/*   Updated: 2022/08/29 16:10:54 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_dinner	dinner;

	if (!setup(argc, argv, &dinner))
		return (1);
	play_philo(&dinner);
	clear_dinner(&dinner);
	return (0);
}
