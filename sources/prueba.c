#include "fractol.h"
#include "mlx.h"

int	close_window(void *param)
{
	void **params;
	void *mlx;
	void *win;

	params = (void **)param;
	mlx = params[0];
	win = params[1];
	mlx_destroy_window(mlx, win);
	exit(0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*params[2];

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Hola caracola");
	params[0] = mlx;
	params[1] = win;
	mlx_hook(win, 17, 0, close_window, params);
	mlx_loop(mlx);
}
