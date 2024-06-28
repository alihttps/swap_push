/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:38:36 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/28 21:42:06 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **source)
{
	
	t_stack	*tmp;

	if (*source)
	{
		tmp = (*source);
		(*source) = (*source)->next;
		tmp->next = (*dest);
		(*dest) = tmp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_putstr("pb\n");
}
