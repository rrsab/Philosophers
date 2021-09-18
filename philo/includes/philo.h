#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_m
{
	int				num_of_philos;
	long			time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				eat_times;
	int				flag_eat_times;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	long			begin_time;
	pthread_mutex_t	print;
}				t_m;

typedef struct s_philo
{
	t_m				*all;
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_eat;
	int				eat_count;
	int				flag_eat_count;
	pthread_mutex_t	*print;
}				t_philo;

int		ft_check_argc(int argc, char *argv[], t_m *all);
int		init_mutex(t_m *all);
t_philo	*init_philo(t_m *all);
int		launch_philos(t_philo *philo, t_m *all);
void	*ft_philo(void *my_struct);
void	*monitor(void *my_struct);
void	print_status(t_philo *philo, char *str, char *clr);
long	get_time(long begin);
void	ft_usleep(int interval);
int		ft_atoi(const char *str);

#endif
