/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:36:11 by psevilla          #+#    #+#             */
/*   Updated: 2024/09/24 20:36:13 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	a;

	i = ft_strlen(str);
	a = c;
	if (!a)
		return ((char *) &str[i]);
	while (i--)
	{
		if (str[i] == a)
			return ((char *) &str[i]);
	}
	return (0);
}
