/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:16:35 by psevilla          #+#    #+#             */
/*   Updated: 2025/02/13 00:55:00 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Fallo de malloc\n");
	exit(EXIT_FAILURE);
}

static void	free_display(t_fractal *fractal)
{
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	malloc_error();
}

static void	start_events(t_fractal *fractal)
{
	mlx_hook(fractal->mlx, KeyPress, KeyPressMask, key_parse, fractal);
	mlx_hook(fractal->mlx, ButtonPress, ButtonPressMask, button_parse, fractal);
	mlx_hook(fractal->mlx, DestroyNotify, StructureNotifyMask, close_fractal, fractal);
	mlx_hook(fractal->mlx, MotionNotify, PointerMotionMask, julia_track);
}

void	start_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGTH, fractal->name);
	if (!fractal->win)
		free_display(fractal);
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGTH);
	if (!fractal->img.img)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		free_display(fractal);
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bpp,
			&fractal->img.line_len,
			&fractal->img.endian);
	start_events(fractal);
}
