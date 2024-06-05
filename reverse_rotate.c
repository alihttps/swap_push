#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		prev = NULL;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void rra (t_stack **a)
{
    reverse_rotate(a);
    ft_putstr("rra\n");
}

void rrb (t_stack **b)
{
    reverse_rotate(b);
    ft_putstr("rra\n");
}

void rrr (t_stack **a , t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putstr("rrr\n");
}

void reverse_rotate_both (t_stack **a,  t_stack **b, t_stack *cheapest_node)
{
    while (*a != cheapest_node && *b != cheapest_node->target)
    {
        rrr(a, b);
    }
    current_index(*a);
    current_index(*b);
}