ifeq ($(MAKECMDGOALS),bonus)
	NAME = philo_bonus
else
	NAME = philo
endif
FLAGS		= -Wall -Wextra -Werror
CFLAGS		= $(FLAGS) -I. -g -pthread
CC			= gcc

ifeq ($(MAKECMDGOALS),bonus)
	OBJS = $(SRCS_BONUS:%.c=%.o)
else
	OBJS = $(SRCS:%.c=%.o)
endif

SRCS 		= src/philo.c \

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
			rm -f gnl/*.o
			make -C libft clean

fclean:		clean
			rm -f $(NAME)
			rm -f philo
			rm -f philo_bonus
			rm -rf a.out*
			rm -rf */a.out*
			rm -rf *.gch
			rm -rf */*.gch

re:			fclean all