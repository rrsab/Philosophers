
/*
**	This function wait return status from forks
*/

#include "philo_bonus.h"

static void	ft_kill(t_vars *vars)
{
	int		i;

	i = -1;
	while (++i < vars->number_p)
	{
		kill(vars->philos[i]->philos, SIGINT);
		waitpid(vars->philos[i]->philos, NULL, 0);
	}
	return ;
}

int	ft_wait_forks(t_vars *vars)
{
	int	ret;
	int	i;

	i = -1;
	while (++i < vars->number_p)
	{
		ret = waitpid(vars->philos[i]->philos, &vars->retval[i], WNOHANG);
		if (vars->retval[i] || ret)
		{
			ft_kill(vars);
			return (0);
		}
		if (i == vars->number_p - 1)
			i = -1;
	}
	return (0);
}
