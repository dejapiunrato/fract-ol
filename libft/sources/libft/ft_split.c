/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:59:36 by psevilla          #+#    #+#             */
/*   Updated: 2024/10/07 16:59:39 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	in_word;
	int	j;

	in_word = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			j++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (j);
}

static char	**free_memory(char **str, int word)
{
	while (word--)
		free(str[word]);
	free(str);
	return (NULL);
}

static char	*str_creator(char const *s, char c, int start)
{
	char	*str;
	int		i;
	int		j;

	j = start;
	while (s[j] && s[j] != c)
		j++;
	i = 0;
	str = (char *)malloc(sizeof(char) * (j - start + 1));
	if (!str)
		return (NULL);
	while (start < j)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		word;

	i = 0;
	word = 0;
	str = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			str[word++] = str_creator(s, c, i);
			if (!str[word - 1])
				return (free_memory(str, word - 1));
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (str);
}
