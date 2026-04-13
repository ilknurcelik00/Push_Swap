NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  parse_args.c \
		  stack_utils.c \
		  ft_utils.c \
		  disorder.c \
		  bench.c \
		  ops_push.c \
		  ops_rotate.c \
		  ops_swap.c \
		  sort_simple.c \
		  sort_medium.c \
		  sort_complex.c \
		  sort_adaptive.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
