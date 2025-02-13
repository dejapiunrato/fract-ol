/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:54:32 by psevilla          #+#    #+#             */
/*   Updated: 2025/02/13 01:06:57 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <fcntl.h>			// open
#include <unistd.h>			// close, read, write
#include <stdlib.h>			// malloc, free, exit
#include <stdio.h>			// perror
#include <string.h>			// strerror
#include <math.h>			// mathematic functions
# include <X11/X.h>			
# include <X11/keysym.h>
# include "libft.h"			// libft functions
# include "mlx.h"			// MiniLibX functions

#define ERROR_MSG "Lo has hecho mal:\n\t./fractol mandelbrot\n\t./fractol julia <valor 1> <valor 2>"

#define WIDTH	1000
#define HEIGTH	1000

typedef struct	s_complex
{
	double	x;
	double	y;
}	t_complex;


typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	julia_r;
	double	julia_i;

}	t_fractal;

// inicialization.c
void	start_fractal(t_fractal *fractal);

// events.c
int		close_fractal(t_fractal *fractal);
int	key_parse(t_fractal *fractal);
int	button_parse(t_fractal *fractal);
int	julia_track(t_fractal *fractal);
#endif
