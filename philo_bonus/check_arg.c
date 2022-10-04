#include "philo.h"

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
			return (exit_with_message("an argument is not valid"));
		res = res * 10 + arg[i] - '0';
		i++;
		if (res > INT_MAX)
			return (exit_with_message("an argument is too large"));
	}
	return (res);
}