/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:16:40 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/28 21:59:23 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**process_input(int ac, char **av)
{
	char	**split;
	char	*joined;

	joined = arg_join(ac, av);
	split = ft_split(joined, ' ');
	free(joined);
	if (!correct_input(split))
	{
		ft_putstr("error");
		free_split(split);
		return (NULL);
	}
	return (split);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	a_len;

	a_len = get_stack_size(*a);
	if (a_len-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (a_len-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (a_len > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		push_a_to_b(a, b);
		a_len--;
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		push_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

static void	helper_stack(t_stack *a, t_stack *b)
{
	if (!stack_sorted(a))
	{
		if (get_stack_size(a) == 2)
			sa(&a);
		else if (get_stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split;

	a = NULL;
	b = NULL;
	split = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac >= 2)
	{
		split = process_input(ac, av);
		if (!split)
			return (1);
	}
	init_stack_a(&a, split);
	helper_stack(a, b);
	printf("size == %d\n", get_stack_size(b));
	printstack(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
