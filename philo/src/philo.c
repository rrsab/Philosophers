/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:25:52 by salyce            #+#    #+#             */
/*   Updated: 2021/09/21 22:25:53 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_m		all;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
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
