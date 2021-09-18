#include "../includes/philo.h"

int	init_mutex(t_m *all)
{
	int	i;

	all->thread = malloc((all->num_of_philos + 1) * sizeof(pthread_t));
	all->mutex = malloc((all->num_of_philos + 1) * sizeof(pthread_mutex_t));
	if (!all->mutex || !all->thread)
	{
		printf("Memory is not located\n");
		return (0);
	}
	i = 0;
	while (i <= all->num_of_philos)
	{
		if (pthread_mutex_init(&all->mutex[i], NULL))
		{
			printf("Mutex is not init\n");
			return (0);
		}
		i++;
	}
	return (1);
}
