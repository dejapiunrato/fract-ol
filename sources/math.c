#include "fractol.h"

double scale_num(double unscaled_num, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * unscaled_num / old_max + new_min;
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
