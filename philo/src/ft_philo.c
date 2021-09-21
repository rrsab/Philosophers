/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:25:45 by salyce            #+#    #+#             */
/*   Updated: 2021/09/21 22:25:46 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_philo(t_philo *philo, int *filled)
{
	long	last_eat;
	long	time;

	time = get_time(philo->all->begin_time);
	last_eat = philo->last_eat;
	if (time - last_eat >= philo->all->time_to_die)
	{
		pthread_mutex_lock(philo->print);
		time = get_time(philo->all->begin_time);
		printf("%s%lu %d %s\n", "\x1b[31m", time, philo->id + 1, DIED);
		return (1);
	}
	if (philo->flag_eat_count)
		(*filled)++;
	return (0);
}

void	*monitor(void *my_struct)
{
	int			i;
	t_philo		*philo;
	int			filled;
	int			flag_eat_times;

	philo = (t_philo *) my_struct;
	flag_eat_times = philo[0].all->flag_eat_times;
	ft_usleep(philo[0].all->time_to_die / 2);
	while (1)
	{
		filled = 0;
		i = 0;
		while (i < philo[0].all->num_of_philos)
		{
			usleep(philo[0].all->time_to_die / 4);
			if (check_philo(&philo[i++], &filled))
				return (NULL);
			if (filled == philo[0].all->num_of_philos && flag_eat_times)
				return (NULL);
		}
	}
}

static void	ft_eating(t_philo *philo)
{
	philo->last_eat = get_time(philo->all->begin_time);
	print_status(philo, EAT, "\x1b[33m");
	philo->eat_count++;
	if (philo->eat_count >= philo->all->eat_times)
		philo->flag_eat_count = 1;
	ft_usleep(philo->all->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*ft_philo(void *my_struct)
{
	t_philo	*philo;

	philo = (t_philo *) my_struct;
	philo->last_eat = get_time(philo->all->begin_time);
	pthread_detach(philo->all->thread[philo->id]);
	if (philo->id % 2 == 1)
		ft_usleep(philo->all->time_to_eat / 2);
	while (1)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, RFORK, "\x1b[34m");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, LFORK, "\x1b[34m");
		ft_eating(philo);
		print_status(philo, SLEEP, "\x1b[35m");
		ft_usleep(philo->all->time_to_sleep);
		print_status(philo, THINK, "\x1b[0m");
	}
	return (NULL);
}
