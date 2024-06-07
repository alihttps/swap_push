/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:23:20 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/07 21:50:39 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_double(char **av)
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

static int	check_zeros(char *av)
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

char	*arg_join(int ac, char **av)
{
	int		i;
	size_t	total_len;
	char	*result;

	i = 1;
	total_len = 0;
	while (i < ac)
	{
		total_len += strlen(av[i]) + 1;
		i++;
	}
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 1;
	while (i < ac)
	{
		strcat(result, av[i]);
		strcat(result, " ");
		i++;
	}
	return (result);
}

int	correct_input(char **av)
{
	int	i;
	int	zeros;

	i = 1;
	zeros = 0;
	while (av[i])
	{
		if (!(is_number(av[i])))
			return (0);
		zeros += check_zeros(av[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (!(check_double(av)))
		return (0);
	return (1);
}
