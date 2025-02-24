/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:22:52 by psevilla          #+#    #+#             */
/*   Updated: 2024/09/24 20:22:53 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	uc;

	uc = c;
	while (*str)
	{
		if (*str == uc)
			return ((char *) str);
		str++;
	}
	if (uc == '\0')
		return ((char *) str);
	return (NULL);
}
