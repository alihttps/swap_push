/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:23:24 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/24 19:25:50 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		*d;
	size_t				i;

	if (dest == src)
		return (dest);
	i = 0;
	ptr = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (n == 0)
		return (d);
	if (n > 0)
	{
		while (n-- > 0)
		{
			d[i] = ptr[i];
			i++;
		}
		return ((char *)dest);
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	int		n;
	char	*ptr;

	n = ft_strlen((char *)str);
	ptr = (char *)malloc(n + 1);
	if (ptr != NULL)
	{
		ft_memcpy(ptr, str, n);
		ptr[n] = '\0';
		return (ptr);
	}
	return (NULL);
}

bool	is_empty_or_spaces(const char *str)
{
	while (*str)
	{
		if (!is_space((unsigned char)*str))
			return (false);
		str++;
	}
	return (true);
}
