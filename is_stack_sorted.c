/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:16:37 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/07 21:46:28 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_min_value(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
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
	return (min_node);
}

t_stack	*find_max_value(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	max = LONG_MIN;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
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

void	min_on_top(t_stack **a)
{
	t_stack	*min;

	min = find_min_value(*a);
	while ((*a)->data != min->data)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}
