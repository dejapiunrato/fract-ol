#include "fractol.h"

static void	put_pixel(int x, int y, int color, t_img *img)
{
	int offset;

	offset = (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

static void	check_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0;
	z.y = 0;
	c.x = scale_num(x, -2, +1, WIDTH);
	c.y = scale_num(x, +2, -2, HEIGTH);
	i = 0;
	color = WHITE;
	while (i < fractal->resolution)
	{
		// z = z² + c
		z = ft_sum(ft_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = scale_num(i, WHITE, BLACK, fractal->resolution);
			put_pixel(x, y, color, &fractal->img);
			return ;
		}
		i++;
	}
	put_pixel(x, y, color, &fractal->img);
}

void	show_fractal(t_fractal	*fractal)
{
	int	x;
	int	y;

	y = -1;
	while (y < HEIGTH)
	{
		x = -1;
		while (x < WIDTH)
		{
			check_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
