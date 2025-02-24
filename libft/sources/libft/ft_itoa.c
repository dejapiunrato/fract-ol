/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:56:43 by psevilla          #+#    #+#             */
/*   Updated: 2024/10/07 16:56:45 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*special(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	if (n == 0 || n == -2147483648)
		return (special(n));
	len = str_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	str[len] = '\0';
	len--;
	while (len >= i)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
