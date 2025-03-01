#include "fractol.h"

static void	put_pixel(int x, int y, int color, t_img *img)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

static void julia_or_mandel(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	check_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = scale_num(x, -2.25, +2.25, WIDTH) * fractal->zoom + fractal->move_x;
	z.y = scale_num(y, +2.25, -2.25, HEIGHT) * fractal->zoom + fractal->move_y;
	julia_or_mandel(&z, &c, fractal);
	i = 0;
	color = BLACK;
	while (i < fractal->resolution)
	{
		z = ft_sum(ft_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = scale_num(i, BLACK, WHITE, fractal->resolution);
			put_pixel(x, y, color, &fractal->img);
			return ;
		}
		++i;	
	}
	put_pixel(x, y, WHITE, &fractal->img);
}

void	show_fractal(t_fractal	*fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			check_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
