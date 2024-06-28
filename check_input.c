/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:23:20 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/28 22:19:10 by aait-bou         ###   ########.fr       */
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
static size_t	calculate_total_length(int ac, char **av)
{
	size_t	len;
	int		i;

	len = 0;
	i = 1;
	while (i < ac)
	{
		len += ft_strlen(av[i]) + 1;
		i++;
	}
	return (len);
}

static char	*join_arguments(int ac, char **av, size_t len)
{
	char	*joined;
	char	*ptr;
	int		i;
	size_t	arg_len;

	joined = (char *)malloc(len + 1);
	if (!joined)
		return (NULL);
	ptr = joined;
	i = 1;
	while (i < ac)
	{
		arg_len = ft_strlen(av[i]);
		ft_memcpy(ptr, av[i], arg_len);
		ptr += arg_len;
		*ptr = ' ';
		ptr++;
		i++;
	}
	*(ptr - 1) = '\0';
	return (joined);
}

char	*arg_join(int ac, char **av)
{
	size_t	len;

	len = calculate_total_length(ac, av);
	return (join_arguments(ac, av, len));
}

int	correct_input(char **av)
{
	int	i;
	int	zeros;

	i = 0;
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
