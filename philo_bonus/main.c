#include "philo.h"

int	main(int argc, char **argv)
{
	t_dinner	dinner;

	if (!setup(argc, argv, &dinner))
		return (1);
	play_philo(&dinner);
	clear_dinner(&dinner);
	return (0);
}
