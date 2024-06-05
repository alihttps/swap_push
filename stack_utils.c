#include "push_swap.h"

void ft_putstr(char *str)
{
    while (*str)
    {
        write (1, str, 1);
        str++;
    }
}

t_stack *create_node(int value)
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return NULL;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

int	get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack *get_tail (t_stack *stack)
{
    if (!stack)
        return NULL;
    while (stack->next)
    {
        stack = stack->next;
    }
    return stack;
}

t_stack *get_before_tail (t_stack *stack)
{
    if (!stack)
        return NULL;
    while (stack->next->next)
    {
        stack = stack->next;
    }
    return stack;
}

void add_bottom(t_stack **stack, int n)
{
    t_stack *new_node;
    t_stack *tail;

    if (!stack)
        return;
    new_node = malloc (sizeof (t_stack));
    if (!new_node)
        return;
    new_node->next = NULL;
    new_node->data = n;
    if(!(*stack))
    {
        *stack = new_node;
        return;
    }
    tail = get_tail(*stack);
    tail->next = new_node;
}

void free_stack (t_stack **stack)
{
    t_stack *tmp;
    t_stack *current = *stack;
    
    if (!stack || !*stack)
        return;

    while (current)
    {
        tmp = current->next;
        current->data = 0;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}