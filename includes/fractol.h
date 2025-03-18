/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:54:32 by psevilla          #+#    #+#             */
/*   Updated: 2025/03/18 17:02:09 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>			// open
# include <unistd.h>			// close, read, write
# include <stdlib.h>			// malloc, free, exit
# include <stdio.h>			// perror
# include <string.h>			// strerror
# include <math.h>			// mathematic functions
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"			// libft functions
# include "mlx.h"			// MiniLibX functions

# define ERROR_MSG1 "Error: invalid input\n\t./fractol mandelbrot\n\t \
	./fractol julia <double> <double>\n"
# define ERROR_MSG2 "Error: invalid input for Julia\n"

// Tamaño de la ventana
# define WIDTH	1000
# define HEIGHT	1000

// Colores
# define BLACK	0X000000
# define WHITE	0xFFFFFF

// Número complejo
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

// Datos de imagen de MiniLibX
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

// Información para representar el fractal
typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	escape_value;
	int		resolution;
	double	julia_x;
	double	julia_y;
	double	move_x;
	double	move_y;
	double	zoom;

}	t_fractal;

// inicialization.c
void		start_fractal(t_fractal *fractal);

// events.c
int			close_fractal(t_fractal *fractal);
int			key_parse(int key, t_fractal *fractal);
int			mouse_parse(int button, int x, int y, t_fractal *fractal);
int			julia_track(t_fractal *fractal);

// utils.c
double		scale_num(double num, double min, double max, double new_max);
t_complex	ft_square(t_complex num);
t_complex	ft_sum(t_complex num1, t_complex num2);
double		ft_atod(const char *s);

// show_fractal.c
void		show_fractal(t_fractal	*fractal);

#endif
