/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:19:21 by psevilla          #+#    #+#             */
/*   Updated: 2024/10/02 22:19:23 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*ptr;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (ft_strdup(""));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && ft_strchr(set, s1[j - 1]))
		j--;
	str = malloc(sizeof(char) * (j - i + 1));
	if (j < i)
		return (ft_strdup(""));
	if (!str)
		return (NULL);
	ptr = str;
	while (i < j)
		*str++ = s1[i++];
	str[j - i] = '\0';
	return (ptr);
}
