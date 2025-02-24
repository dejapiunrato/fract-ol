/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piesito <piesito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:57:00 by piesito           #+#    #+#             */
/*   Updated: 2024/10/25 01:45:08 by piesito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chr(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	if (!str)
		return (ft_printf("(null)"));
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (ft_printf("(nil)"));
	else
	{
		i += ft_printf("0x");
		i += ft_print_num(ptr, 'x');
	}
	return (i);
}

int	ft_print_num(long n, char c)
{
	char	*chars;
	int		i;
	int		base;

	i = 0;
	if (c == 'x')
		chars = "0123456789abcdef";
	if (c == 'X')
		chars = "0123456789ABCDEF";
	if (c == 'd' || c == 'i' || c == 'u')
		chars = "0123456789";
	if (c == 'u')
		n = (unsigned long)n;
	base = ft_strlen(chars);
	if (n < 0)
		return (ft_print_chr('-') + ft_print_num(-n, c));
	else if (n < base)
		return (ft_print_chr(chars[n]));
	else
	{
		i = ft_print_num(n / base, c);
		return (i + ft_print_num(n % base, c));
	}
}
