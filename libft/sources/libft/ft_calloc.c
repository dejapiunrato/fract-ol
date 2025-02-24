/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:32:35 by psevilla          #+#    #+#             */
/*   Updated: 2024/09/27 16:32:36 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	n_size;
	size_t	i;	
	void	*ptr;

	n_size = n * size;
	ptr = malloc(n_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < n_size)
		((char *)ptr)[i++] = 0;
	return (ptr);
}
