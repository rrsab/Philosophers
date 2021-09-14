#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int			l_fork;
	int			r_fork;
	pthread_t	pthread;
}				t_philo;

typedef struct	s_m
{
	t_philo		**philoss;
	int				number_get;
	struct timeval	time;
	int				number_p;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long int		valid_time;
	long int		start_time;
	int				number_eat;
	int				*retval;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*number_get_mutex;
	pthread_mutex_t	*global_mutex;
	pthread_mutex_t	*print_mutex;
	int				end;
}				t_m;

int		ft_atoi(const char *str);
int 	ft_error(char *str, int ret);
size_t	ft_strlen(const char *s);
int		ft_check_argc(int argc, char **argv, t_m *vars);
int		ft_create_mutex(t_m *vars);
void	ft_free(t_m *vars);
void	*ft_philo(void *args);
int		ft_philo_number(t_m *vars);

#endif
