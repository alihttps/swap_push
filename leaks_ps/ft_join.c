/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:48:06 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/28 22:04:31 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
