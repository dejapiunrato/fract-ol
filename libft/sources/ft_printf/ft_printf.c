/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piesito <piesito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:52:36 by piesito           #+#    #+#             */
/*   Updated: 2024/10/25 01:49:03 by piesito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_print_chr(va_arg(args, int));
	else if (c == 's')
		i += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		i += ft_print_ptr((unsigned long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		i += ft_print_num((long)va_arg(args, int), c);
	else if (c == 'x' || c == 'X' || c == 'u')
		i += ft_print_num((long)va_arg(args, unsigned int), c);
	else if (c == '%')
		i += write(1, "%", 1);
	else
		i += write(1, &c, 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
			i += ft_parse(*(++str), args);
		else
			i += write(1, str, 1);
		++str;
	}
	va_end(args);
	return (i);
}
