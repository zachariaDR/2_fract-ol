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
	else
	{
		ft_putstr_fd("Available fractals: mandel, julia, ship\n", 1);
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fract	*fractal;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fractol <fractal>\n", 1);
		ft_putstr_fd("Available fractals: mandelbrot, julia, burningship\n", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fract));
	init_fract(fractal, argv[1]);
	init_mlx(fractal);
	mlx_key_hook(fractal->win, key_handler, fractal);
	mlx_mouse_hook(fractal->win, ft_zoom, fractal);
	mlx_hook(fractal->win, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}

// 