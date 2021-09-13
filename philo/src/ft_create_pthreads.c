#include "../includes/philo.h"

static int	ft_allocate(t_m *vars)
{
	int	i;

	i = 0;
	while (i < vars->number_p)
	{
		vars->philoss[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!(vars->philoss[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_create_pthreads(t_m *vars)
{
	int	i;
	int	ret;

	vars->philoss = (t_philo **)malloc(sizeof(t_philo *) \
			* (vars->number_p + 1));
	if (!(vars->philoss))
		return (-1);
	vars->philoss[vars->number_p] = NULL;
	if (ft_allocate(vars))
		return 

}