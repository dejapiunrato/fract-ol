#include "fractol.h"

int	close_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

/* int	key_parse(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_fractal(fractal);

	show_fractal(fractal);
	return (0);
} */
/*
int	button_parse(t_fractal *fractal)
{
	// por hacer
}

int	julia_track(t_fractal *fractal)
{
	// por hacer
}*/
