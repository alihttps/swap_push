/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:23:20 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/26 18:46:47 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] != NULL)
	{
		j = i + 1;
		while (av[j] != NULL)
		{
			if (nums_cmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_zeros(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i])
		return (0);
	return (1);
}

bool	correct_input(char **av)
{
	int	i;
	int	zeros;

	i = 0;
	zeros = 0;
	while (av[i])
	{
		if (!(is_number(av[i])))
			return (false);
		zeros += check_zeros(av[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (!(check_double(av)))
		return (0);
	return (true);
}
