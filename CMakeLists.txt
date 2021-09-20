cmake_minimum_required(VERSION 3.20)
project(Philosophers)

set(CMAKE_CXX_STANDARD 14)

include_directories(philo/includes)
include_directories(philo/src)
include_directories(philo_bonus/includes)
include_directories(philo_bonus/src)

add_executable(Philosophers
        philo/src/ft_check_argc.c
        philo/src/ft_mutex.c
        philo/src/ft_utils1.c
        philo/src/philo.c
        philo/src/ft_philo.c
        philo/src/ft_create_pthreads.c
        philo_bonus/src/ft_check_argc.c
        philo_bonus/src/ft_init.c
        philo_bonus/src/ft_utils1.c
        philo_bonus/src/philo.c
        philo_bonus/src/ft_printing.c)
