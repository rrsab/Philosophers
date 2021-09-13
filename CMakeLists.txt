cmake_minimum_required(VERSION 3.20)
project(Philosophers)

set(CMAKE_CXX_STANDARD 14)

include_directories(philo/includes)
include_directories(philo/src)

add_executable(Philosophers
        philo/src/ft_check_argc.c
        philo/src/ft_mutex.c
        philo/src/ft_pthread.c
        philo/src/ft_utils1.c
        philo/src/philo.c)
