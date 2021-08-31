
/*
**	This function create semaphore
*/

#include "philo_bonus.h"

int	ft_create_semaphore(t_vars *vars)
{
	sem_unlink(SEM_NAME_1);
	sem_unlink(SEM_NAME_2);
	vars->sema = sem_open(SEM_NAME_1, O_CREAT, S_IRWXG, vars->number_p);
	if (vars->sema == SEM_FAILED)
		return (-1);
	vars->sema_p = sem_open(SEM_NAME_2, O_CREAT, S_IRWXG, 1);
	if (vars->sema_p == SEM_FAILED)
		return (-1);
	return (0);
}
