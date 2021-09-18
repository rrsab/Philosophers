#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_m	all;
	t_philo			*philo;

	if (argc == 6 || argc == 5)
	{
		if (!ft_check_argc(argc, argv, &all))
			return (0);
		if (!init_mutex(&all))
			return (0);
		philo = init_philo(&all);
		if (!philo)
			return (0);
		if (!launch_philos(philo, &all))
			return (0);
		free(all.thread);
		free(philo);
		free(all.mutex);
		return (0);
	}
	else
	{
		printf("Not valid arguments\n");
		return (0);
	}
}