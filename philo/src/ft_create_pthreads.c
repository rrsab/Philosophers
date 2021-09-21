/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pthreads.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:25:37 by salyce            #+#    #+#             */
/*   Updated: 2021/09/21 22:25:38 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	set_vars(t_philo *philo, t_m *all, int i)
{
	philo->all = all;
	philo->id = i;
	if (i == 0)
		philo->left_fork = &all->mutex[all->num_of_philos - 1];
	else
		philo->left_fork = &all->mutex[i - 1];
	philo->right_fork = &all->mutex[i];
	philo->eat_count = 0;
	philo->flag_eat_count = 0;
	philo->print = &all->mutex[all->num_of_philos];
}

t_philo	*init_philo(t_m *all)
{
	t_philo	*philo;
	int		i;

	philo = malloc(all->num_of_philos * sizeof(t_philo));
	if (!philo)
	{
		printf("Memory is not located\n");
		return (NULL);
	}
	i = -1;
	while (++i < all->num_of_philos)
		set_vars(&philo[i], all, i);
	return (philo);
}

int	launch_philos(t_philo *philo, t_m *all)
{
	int	i;
	int	nop;

	i = 0;
	philo->all->begin_time = get_time(0);
	while (i < all->num_of_philos)
	{
		pthread_create(&all->thread[i], NULL, ft_philo, (void *) &philo[i]);
		i++;
	}
	nop = all->num_of_philos;
	pthread_create(&all->thread[nop], NULL, monitor, (void *) philo);
	pthread_join(all->thread[all->num_of_philos], NULL);
	return (1);
}
