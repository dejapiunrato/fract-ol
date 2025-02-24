/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:32:23 by psevilla          #+#    #+#             */
/*   Updated: 2024/09/27 16:32:24 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int			i;
	int			neg;
	long int	num;

	i = 0;
	neg = 1;
	num = 0;
	while ((s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r')))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return ((int)(num * neg));
}
