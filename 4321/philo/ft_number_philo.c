
/*
**	This function return number of philosopher
*/

#include "philo.h"

int	ft_number_philo(t_vars *vars)
{
	int	number;

	pthread_mutex_lock(vars->number_get_mutex);
	number = vars->number_get++;
	pthread_mutex_unlock(vars->number_get_mutex);
	if (number > 0)
	{
		vars->philos[number]->fork_1 = number;
		vars->philos[number]->fork_2 = vars->philos[number]->fork_1 - 1;
	}
	else
	{
		vars->philos[number]->fork_1 = 0;
		vars->philos[number]->fork_2 = vars->number_p - 1;
	}
	return (number);
}
