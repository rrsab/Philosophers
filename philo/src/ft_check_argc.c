#include "../includes/philo.h"

int	ft_check_argc(int argc, char *argv[], t_m *all)
{
	all->flag_eat_times = 0;
	all->num_of_philos = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		all->flag_eat_times = 1;
		all->eat_times = ft_atoi(argv[5]);
	}
	if (all->num_of_philos < 1 || all->time_to_die < 1 || all->time_to_eat < 1 \
	|| all->time_to_sleep < 1 || (all->flag_eat_times && all->eat_times < 1))
	{
		printf("Not valid arguments\n");
		return (0);
	}
	return (1);
}