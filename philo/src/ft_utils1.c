#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	int				result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == ' ') || ((str[i] > 8) && (str[i] < 14)))
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		if ((result > 2147483648 && sign == -1) || \
			(result > 2147483647 && sign == 1))
			return (-1);
		i++;
	}
	return (sign * result);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_error(char *str, int ret)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	return (ret);
}

void	ft_free(t_m *vars)
{
	int	i;

	i = -1;
	while (vars->philoss[++i])
		free(vars->philoss[i]);
	free(vars->philoss);
	free(vars->retval);
	while (--vars->number_p + 1)
		pthread_mutex_destroy(&vars->forks[vars->number_p]);
	free(vars->forks);
	pthread_mutex_destroy(vars->number_get_mutex);
	free(vars->number_get_mutex);
	pthread_mutex_destroy(vars->global_mutex);
	free(vars->global_mutex);
	pthread_mutex_destroy(vars->print_mutex);
	free(vars->print_mutex);
}
