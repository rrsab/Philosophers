/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:26:07 by salyce            #+#    #+#             */
/*   Updated: 2021/09/21 22:26:08 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)))
	{	
		if (*(s1 + i) != *(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

void	print_status(t_data *data, int ph_id, char *str, char *clr)
{
	int			len;
	uint64_t	tt;

	len = 0;
	tt = 0;
	while (str[len])
		len++;
	tt = timestamp() - data->table->start_time;
	if (tt >= 0)
	{
		sem_wait(data->table->message);
		printf("%s%llu %d %s\n", clr, tt, ph_id + 1, str);
	}
	if (ft_strcmp(str, DIED))
		sem_post(data->table->message);
}

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 8);
	write(2, str, len);
	write(2, "\n", 1);
	exit (1);
}
