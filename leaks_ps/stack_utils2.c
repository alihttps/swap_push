/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:20:52 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/28 20:44:36 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (is_digit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void free_stack(t_stack **stack) {
    t_stack *current;
    t_stack *next;

    if (!stack || !(*stack)) return;

    current = *stack;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}
