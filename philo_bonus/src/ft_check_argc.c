/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:25:59 by salyce            #+#    #+#             */
/*   Updated: 2021/09/21 22:26:00 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	ft_atoi_int(const char *str)
{
	int			negative;
	int			i;
	long		convert;

	negative = 1;
	i = 0;
	convert = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -negative;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		convert = convert * 10 + (str[i++] - '0') * negative;
	if (convert > 2147483647 || convert < -2147483648)
		write_error("Integer overflow");
	return (convert);
}

int	ft_check_argc(t_m *table, char **argv)
{
	table->nbr_ph = ft_atoi_int(argv[1]);
	table->t_die = ft_atoi_int(argv[2]);
	table->t_eat = ft_atoi_int(argv[3]);
	table->t_sleep = ft_atoi_int(argv[4]);
	table->all_ate = 0;
	if (argv[5])
	{
		table->must_to_eat = ft_atoi_int(argv[5]);
		if (table->must_to_eat <= 0)
			return (1);
	}
	else
		table->must_to_eat = INT_MAX;
	if (table->nbr_ph <= 0 || table->t_die < 0 || table->t_eat < 0
		|| table->t_sleep < 0 || table->nbr_ph > 200)
		return (1);
	return (0);
}
