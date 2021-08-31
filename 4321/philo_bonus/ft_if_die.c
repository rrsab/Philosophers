
/*
**	This function check die philosopher or not
*/

#include "philo_bonus.h"

int	ft_if_die(t_vars *vars, int number_philo, long int *time)
{
	if (time[0] != 0 && time[1] != 0
		&& (((vars->time.tv_sec - time[0]) * 1000000 + vars->time.tv_usec)
			- time[1]) > vars->time_to_die * 1000)
	{
		ft_print_status(vars, number_philo + 1, STATUS_DIE);
		return (1);
	}
	return (0);
}
