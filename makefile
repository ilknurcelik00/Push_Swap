NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = stack_utils.c \
              ft_utils.c \
              ops_swap.c \
              ops_push.c \
              ops_rotate.c \
              parse_args.c \
              disorder.c \
              sort_simple.c \
              sort_medium.c \
              sort_complex.c \
              sort_adaptive.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re