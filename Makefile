NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = main.c \
          bench.c \
          disorder.c \
          ft_utils.c \
          ft_utils2.c \
          ops_push.c \
          ops_rotate.c \
          ops_rev_rotate.c \
          ops_swap.c \
          parse_args.c \
          parse_token.c \
          sort_adaptive.c \
          sort_complex.c \
          sort_medium.c \
          sort_simple.c \
          stack_utils.c \
          stack_utils2.c \
          stack_utils3.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re