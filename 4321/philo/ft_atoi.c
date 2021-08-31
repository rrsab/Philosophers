/
#include "philo.h"

static int	ft_if(char a)
{
	if (a > '9' || a < '0')
		return (1);
	return (0);
}

int	ft_atoi(const char *a)
{
	int			z;
	long int	q;

	z = 1;
	q = 0;
	while ((*a == ' ') || (*a <= 13 && *a >= 7))
		a++;
	if (*a == '+' && *(a + 1) == '-')
		return (0);
	if (*a == '+')
		a++;
	if (*a == '-')
	{
		z = z * (-1);
		a++;
	}
	while (*a <= '9' && *a >= '0')
	{
		if (q > 2147483648 && z == -1)
			return (0);
		if ((q > 2147483647 && z == 1) || (*(a + 1) && ft_if(*(a + 1))))
			return (-1);
		q = q * 10 + *a++ - '0';
	}
	return (q * z);
}
