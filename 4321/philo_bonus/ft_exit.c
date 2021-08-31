
#include "philo_bonus.h"

int	ft_exit(t_vars *vars, int status)
{
	int	i;

	i = -1;
	while (++i < vars->number_p)
		free(vars->philos[i]);
	free(vars->philos);
	free(vars->retval);
	exit(status);
	return (0);
}
