/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:35:13 by ide-spir          #+#    #+#             */
/*   Updated: 2022/08/29 16:18:28 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_arg(char *arg)
{
	int				i;
	unsigned long	res;

	i = 0;
	res = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (exit_with_message("An argument is not valid"));
		res = res * 10 + arg[i] - '0';
		i++;
		if (res > INT_MAX)
			return (exit_with_message("An argument is too large"));
	}
	return (res);
}
