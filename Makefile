SRCS = \
	check_input_utils.c \
	init_stack_a.c \
	is_stack_sorted.c \
	rotate.c \
	stack_utils.c \
	turk_algo.c \
	check_input.c \
	ft_split.c \
	init_stack_b.c \
	main.c \
	push.c \
	reverse_rotate.c \
	stack_utils2.c \
	swap.c

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation done."

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
