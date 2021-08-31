
#include "philo.h"

void	ft_free(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->philos[++i])
		free(vars->philos[i]);
	free(vars->philos);
	free(vars->retval);
	while (--vars->number_p + 1)
		pthread_mutex_destroy(&vars->forks[vars->number_p]);
	free(vars->forks);
	pthread_mutex_destroy(vars->number_get_mutex);
	free(vars->number_get_mutex);
	pthread_mutex_destroy(vars->global_mutex);
	free(vars->global_mutex);
	pthread_mutex_destroy(vars->print_mutex);
	free(vars->print_mutex);
}
