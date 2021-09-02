#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_m	vars;

	memset(&vars, '\0', sizeof(vars));
	if (ft_check_argc(argc, argv, $vars))
		return (ft_error("Invalid arguments\n", -1));
	if (ft_create_mutex(&vars))
		return (-1);
	


}