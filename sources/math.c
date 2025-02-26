#include "fractol.h"

double	scale_num(double num, double min, double max, double new_max)
{
	return (-2 + ((num - min) / (max - min)) * new_max);
}

t_complex	ft_square(t_complex num)
{
	// [ ] Falta por hacer
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
