/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:33:15 by ide-spir          #+#    #+#             */
/*   Updated: 2022/10/05 09:33:15 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_check_arg(char *arg)
{
	int				i;
	unsigned long	res;

	i = 0;
	res = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (ft_exit_with_message("an argument is not valid"));
		res = res * 10 + arg[i] - '0';
		i++;
		if (res > INT_MAX)
			return (ft_exit_with_message("an argument is too large"));
	}
	return (res);
}
