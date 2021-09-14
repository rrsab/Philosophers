#include "../includes/philo.h"

int	ft_philo_number(t_m *vars)
{
	int	number;

	pthread_mutex_lock(vars->number_get_mutex);
	number = vars->number_get++;
	pthread_mutex_unlock(vars->number_get_mutex);
	if (number > 0)
	{
		vars->philoss[number]->l_fork = number;
		vars->philoss[number]->r_fork = vars->philoss[number]->l_fork - 1;
	}
	else
	{
		vars->philoss[number]->l_fork = 0;
		vars->philoss[number]->r_fork = vars->number_p - 1;
	}
	return (number);
}