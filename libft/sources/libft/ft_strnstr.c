/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:38:21 by psevilla          #+#    #+#             */
/*   Updated: 2024/09/27 16:38:22 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	j = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (j < n && s1[j])
	{
		if (s1[j] == s2[0])
		{
			i = 0;
			while (i < n - j && s1[j + i] == s2[i] && s2[i])
				i++;
			if (s2[i] == 0)
				return ((char *) &s1[j]);
		}
		j++;
	}
	return (NULL);
}
