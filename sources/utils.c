/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:58:12 by psevilla          #+#    #+#             */
/*   Updated: 2025/03/18 16:57:51 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_num(double unscaled, double min, double new_max, double old_max)
{
	return ((new_max - min) * unscaled / old_max + min);
}

t_complex	ft_square(t_complex num)
{
	t_complex	result;

	result.x = (num.x * num.x) - (num.y * num.y);
	result.y = 2 * num.x * num.y;
	return (result);
}

t_complex	ft_sum(t_complex num1, t_complex num2)
{
	t_complex	result;

	result.x = num1.x + num2.x;
	result.y = num1.y + num2.y;
	return (result);
}

static int	ft_atdo_sign(const char *s, int *i)
{
	int	neg;

	neg = 1;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			neg = -1;
		(*i)++;
	}
	return (neg);
}

double	ft_atod(const char *s)
{
	int		i;
	int		neg;
	double	num;
	double	decimal;

	i = 0;
	num = 0.0;
	decimal = 0.1;
	while ((s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r')))
		i++;
	neg = ft_atdo_sign(s, &i);
	while (ft_isdigit(s[i]))
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
	{
		num += (s[i] - '0') * decimal;
		decimal /= 10;
		i++;
	}
	return (num * neg);
}
