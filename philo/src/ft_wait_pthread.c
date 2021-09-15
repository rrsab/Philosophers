#include "../includes/philo.h"

int	ft_wait_pthread(t_m *vars)
{
	int	ret;
	int	i;

	i = -1;
	while (vars->philoss[++i] != NULL)
	{
		ret = pthread_join(vars->philoss[i]->pthread, (void **)&vars->retval[i]);
		if (ret != 0)
			return (-1);
	}
	return (0);
}
