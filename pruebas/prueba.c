#include "../minilibx_linux/mlx.h"
#include <fcntl.h>			// open
#include <unistd.h>			// close, read, write
#include <stdlib.h>			// malloc, free, exit
#include <stdio.h>			// perror
#include <string.h>			// strerror
#include <math.h>			// mathematic functions
# include <X11/X.h>
# include <X11/keysym.h>

int	close_win(void **params)
{
	void	*win;
	void	*mlx;

	win = params[];
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*params[2];

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 400,  400, "Hola Caracola");
	if (!win)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (1);
	}
	params[0] = mlx;
	params[1] = win;
	mlx_hook(win, DestroyNotify, StructureNotifyMask, close_win, (void **)param);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
