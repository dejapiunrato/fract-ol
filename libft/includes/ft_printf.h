/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:24:36 by piesito           #+#    #+#             */
/*   Updated: 2025/02/12 12:20:49 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> 
# include "libft.h"

// ft_printf.c
int	ft_printf(const char *str, ...);
int	ft_parse(char c, va_list args);

// ft_printf_utils.c
int	ft_print_chr(char c);
int	ft_print_str(char *str);
int	ft_print_ptr(unsigned long ptr);
int	ft_print_num(long n, char c);

#endif
