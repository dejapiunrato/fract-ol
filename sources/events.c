/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:54:32 by psevilla          #+#    #+#             */
/*   Updated: 2025/03/04 17:55:14 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int	key_parse(int key, t_fractal *fractal)
{
	if (key == XK_Escape)
		close_fractal(fractal);
	if (key == XK_Right)
		fractal->move_x += 0.2 * fractal->zoom;
	else if (key == XK_Left)
		fractal->move_x -= 0.2 * fractal->zoom;
	else if (key == XK_Up)
		fractal->move_y += 0.2 * fractal->zoom;
	else if (key == XK_Down)
		fractal->move_y -= 0.2 * fractal->zoom;
	show_fractal(fractal);
	return (0);
}

int	mouse_parse(int button, int x, int y, t_fractal *fractal)
{
	fractal->move_x = scale_num(x, -2.25, +2.25, WIDTH);
	fractal->move_y = scale_num(y, +2.25, -2.25, HEIGHT);
	if (button == Button4)
		fractal->zoom *= 0.9;
	else if (button == Button5)
		fractal->zoom *= 1.1;
	show_fractal(fractal);
	return (0);
}
