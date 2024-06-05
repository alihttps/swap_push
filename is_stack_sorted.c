#include "push_swap.h"

bool stack_sorted(t_stack *stack)
{
    if (!stack)
        return 1;
    while (stack->next)
    {
        if (stack->data > stack->next->data)
            return false;
        stack = stack->next;
    }
    return true;
}

t_stack *find_min_value (t_stack *stack)
{
    long min;
    t_stack *min_node;

    if (!stack)
        return NULL;
    min = LONG_MAX;
    while (stack)
    {
        if (stack->data < min)
        {
            min = stack->data;
            min_node = stack;
        }
        stack = stack->next;
    }
    return min_node;
}

t_stack *find_max_value (t_stack *stack)
{
    long max = LONG_MIN;
    t_stack *max_node;

    if (!stack)
        return NULL;
    while (stack)
    {
        if (stack->data > max)
        {
            max = stack->data;
            max_node = stack;
        }
        stack = stack->next;
    }
    return max_node;
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_max_value(*a);
	if (biggest_node == *a) 
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a); 
	if ((*a)->data > (*a)->next->data)
		sa(a);
}