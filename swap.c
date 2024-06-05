#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}

void sa(t_stack **a)
{
    swap(a);
    ft_putstr ("sa\n");
}

void sb(t_stack **b)
{
    swap(b);
    ft_putstr ("sb\n");
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_putstr("ss\n");
}