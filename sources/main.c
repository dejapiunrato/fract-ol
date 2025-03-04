/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:51:12 by psevilla          #+#    #+#             */
/*   Updated: 2025/03/04 17:51:18 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	input_error(int error)
{
	if (error == 1)
		ft_putstr_fd(ERROR_MSG1, STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd(ERROR_MSG2, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = ft_atod(argv[2]);
			fractal.julia_y = ft_atod(argv[3]);
			if (!fractal.julia_x || !fractal.julia_y)
				input_error(2);
		}
		start_fractal(&fractal);
		show_fractal(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
		input_error(1);
	return (0);
}
