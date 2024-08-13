#include "fract_ol.h"

int	exit_fractal(t_fract *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
	free(fractal);
	exit(EXIT_FAILURE);
	return (0);
}

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
	else
	{
		ft_putstr_fd("Available fractals: mandel, julia, tri\n", 1);
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fract	*fractal;

	if (ac != 2 && ac != 4)
	{
		ft_putstr_fd("Usage: ./fractol <fractal>\n", 1);
		ft_putstr_fd("Available fractals: mandelbrot, julia, tricron\n", 1);
		exit(1);
	}
	fractal = malloc(sizeof(t_fract));
	if (ac == 4)
		init_fract(fractal, av[1], ft_atod(av[2]), ft_atod(av[3]));
	else
		init_fract(fractal, av[1], 0.42, 0.42);
	init_mlx(fractal);
	mlx_key_hook(fractal->win, key_handler, fractal);
	mlx_mouse_hook(fractal->win, ft_zoom, fractal);
	mlx_hook(fractal->win, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, av[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
 