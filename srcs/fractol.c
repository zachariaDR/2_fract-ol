/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:58:25 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/16 00:11:53 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	draw_fractal(t_fract *fractal, char *query)
{
	if (ft_strncmp(query, "mandel", 7) == 0)
		plotting_mandelbrot(fractal);
	else if (ft_strncmp(query, "julia", 6) == 0)
		plotting_julia(fractal);
	else if (ft_strncmp(query, "ship", 5) == 0)
		plotting_burnship(fractal);
	else if (ft_strncmp(query, "tri", 4) == 0)
		plotting_tricorn(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fract	*fractal;

	check_args(ac, av);
	fractal = (t_fract *)malloc(sizeof(t_fract));
	if (!fractal)
		exit(EXIT_FAILURE);
	if (ac == 4)
		init_fract(fractal, av[1], ft_atod(av[2]), (ft_atod(av[3]) * -1));
	else
		init_fract(fractal, av[1], 0.42, 0.42);
	init_mlx(fractal);
	mlx_key_hook(fractal->win, key_handler, fractal);
	mlx_mouse_hook(fractal->win, ft_zoom, fractal);
	mlx_hook(fractal->win, DestroyNotify, 0, exit_fractal, fractal);
	draw_fractal(fractal, av[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
