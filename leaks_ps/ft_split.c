/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <aait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:25:55 by aait-bou          #+#    #+#             */
/*   Updated: 2024/06/28 19:48:55 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char sep)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == sep)
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*allocate(char const **s, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while ((*s)[i] && (*s)[i] != sep)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (**s && **s != sep)
	{
		word[i++] = **s;
		(*s)++;
	}
	word[i] = '\0';
	while (**s && **s == sep)
		(*s)++;
	return (word);
}

// void	free_split(char **splitted)
// {
// 	int	i;

// 	i = 0;
// 	while (splitted[i])
// 		free(splitted[i++]);
// 	free(splitted);
// }

static void	free_split(char **s, int n)
{
	if (!s)
		return ;
	while (n--)
		free(s[n]);
	free(s);
}

char	**ft_split(char const *s, char sep)
{
	size_t	words;
	char	**splitted;
	size_t	i;

	if (!s)
		return (NULL);
	words = count_words(s, sep);
	splitted = (char **)malloc(sizeof(char *) * (words + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	while (*s && *s == sep)
		s++;
	while (i < words)
	{
		splitted[i] = allocate(&s, sep);
		if (!splitted[i])
		{
			free_split(splitted, i);
			return (NULL);
		}
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}
