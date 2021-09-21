NAME		= philo
FLAGS		= -Wall -Wextra -Werror
CFLAGS		= $(FLAGS) -I. -g -pthread
CC			= gcc

OBJS = $(SRCS:%.c=%.o)

SRCS 		= src/philo.c \
				src/ft_check_argc.c \
				src/ft_mutex.c \
				src/ft_utils1.c \
				src/ft_philo.c \
				src/ft_create_pthreads.c \

SRCS_BONUS	=
INCLUDE		= includes/philo.h \

.PHONY: all clean fclean re libft norm

.o:.c 		$(INCLUDE)
			$(CC) $(CFLAGS) $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(CC) $(OBJS) -o $(NAME)

norm:
			norminette $(SRCS)
			norminette $(INCLUDE)

clean:
			rm -f src/*.o

fclean:		clean
			rm -f $(NAME)
			rm -f philo
			rm -f philo_bonus
			rm -rf a.out*
			rm -rf */a.out*
			rm -rf *.gch
			rm -rf */*.gch

re:			fclean all