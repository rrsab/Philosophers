
/*
**	This function return number of philosopher
*/

#include "philo_bonus.h"

int	ft_number_philo(t_vars *vars)
{
	int	number;

	number = vars->number_get++;
	return (number);
}
