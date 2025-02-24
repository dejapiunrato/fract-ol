/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:35:34 by psevilla          #+#    #+#             */
/*   Updated: 2024/09/27 16:35:35 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*d;
	char	*aux;

	size = ft_strlen(s) + 1;
	d = malloc(size);
	if (d == NULL)
		return (NULL);
	aux = d;
	while (*s)
		*d++ = *s++;
	*d = '\0';
	return (aux);
}
