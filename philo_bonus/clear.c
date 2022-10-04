#include "philo.h"

void	clear_dinner(t_dinner *dinner)
{
	sem_close(dinner->sem_print);
	sem_close(dinner->sem_dead);
	sem_close(dinner->sem_forks);
	sem_unlink("sem_print");
	sem_unlink("sem_forks");
	sem_unlink("sem_dead");
}
