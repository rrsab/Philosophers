
/*
** This function write str in std_out and return ret
*/

#include "philo_bonus.h"

int	ft_print(char *str, int ret)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	return (ret);
}
