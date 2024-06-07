/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:23:24 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/07 21:56:41 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int av)
{
	return (av >= '0' && av <= '9');
}

int	is_sign(int av)
{
	return (av == '+' || av == '-');
}

int	is_space(int av)
{
	return (av == ' ' || av == '\t' || av == '\n' || av == '\r' || av == '\f'
		|| av == '\v');
}

int	is_number(char *av)
{
	int	i;

	i = 0;
	while (is_space(av[i]))
		i++;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (is_digit(av[i]) && av[i] != '\0')
		i++;
	if (!is_digit(av[i]) && av[i] != '\0')
		return (0);
	else
		return (1);
}

int	nums_cmp(char *av1, char *av2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (av1[i] == '+')
		i++;
	if (av2[j] == '+')
		j++;
	while (av1[i] == '0')
		i++;
	while (av2[j] == '0')
		j++;
	while (av1[i] != '\0' && av2[j] != '\0' && av1[i] == av2[j])
	{
		i++;
		j++;
	}
	if (av1[i] == '\0' && av2[j] == '\0')
		return (0);
	if (av1[i] == '\0' || av2[j] == '\0')
		return (1);
	return (av1[i] - av2[j]);
}
