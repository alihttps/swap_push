SRCS = \
	check_input_utils.c \
	check_input_utils2.c \
	init_stack_a.c \
	is_stack_sorted.c \
	rotate.c \
	stack_utils.c \
	turk_algo.c \
	check_input.c \
	init_stack_b.c \
	main.c \
	ft_split.c \
	ft_join.c \
	push.c \
	reverse_rotate.c \
	stack_utils2.c \
	swap.c


OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) -g3 -fsanitize=address $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation done."

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
