/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h_                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:54:32 by psevilla          #+#    #+#             */
/*   Updated: 2025/02/27 17:26:55 by psevilla         ###   ########.fr       */
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

#define ERROR_MSG "Lo has hecho mal:\n\t./fractol mandelbrot\n\t./fractol julia <valor 1> <valor 2>\n"

// Tamaño de la ventana
#define WIDTH	1000
#define HEIGHT	1000

// Colores
#define BLACK	0X000000
#define WHITE	0xFFFFFF
#define YELLOW	0xFFFF00
#define RED		0xFF0000
#define ORANGE	0xFFA500
#define BLUE	0x0000FF
#define GREEN	0x008000

// Número complejo
typedef struct	s_complex
{
	double	x;
	double	y;
}	t_complex;

// Datos de imagen de MiniLibX
typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

// Información para representar el fractal
typedef struct	s_fractal
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	escape_value;
	int		resolution;
	double	julia_x;
	double	julia_y;

}	t_fractal;

// inicialization.c
void		start_fractal(t_fractal *fractal);

// events.c
int			close_fractal(t_fractal *fractal);
int			key_parse(t_fractal *fractal);
int			button_parse(t_fractal *fractal);
int			julia_track(t_fractal *fractal);

// math.c
double		scale_num(double num, double min, double max, double new_max);
t_complex	ft_square(t_complex num);
t_complex	ft_sum(t_complex num1, t_complex num2);

// show_fractal.c
void		show_fractal(t_fractal	*fractal);

#endif
