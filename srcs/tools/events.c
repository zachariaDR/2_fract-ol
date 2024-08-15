#include "fract_ol.h"

int	exit_fractal(t_fract *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_zoom(int button, int x, int y, t_fract *f)
{
	double mouse_re, mouse_im;
	mouse_re = (f->re_min + (f->re_max - f->re_min) * ((double)x / f->width))
		* f->zoom;
	mouse_im = (f->im_max - (f->im_max - f->im_min) * ((double)y / f->heigth))
		* f->zoom;
	if (button == 4)
	{
		f->zoom *= 0.5;
		// f->max_iter+=1;
	}
	else if (button == 5)
	{
		f->zoom *= 1.5;
		// f->max_iter-=1;
	}
	else
		return (0);
	f->shift_x += mouse_re - (f->re_min + (f->re_max - f->re_min) * ((double)x
				/ f->width)) * f->zoom;
	f->shift_y += mouse_im - (f->im_max - (f->im_max - f->im_min) * ((double)y
				/ f->heigth)) * f->zoom;
	draw_fractal(f, f->name);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int	key_handler(int keysym, t_fract *fractal)
{
	if (keysym == ESC)
		exit_fractal(fractal);
	else if ((keysym == LEFT && fractal->zoom > 0.5) || (keysym == RIGHT
			&& fractal->zoom < 0.5))
		fractal->shift_x += 0.5 * fractal->zoom;
	else if ((keysym == RIGHT && fractal->zoom > 0.5) || (keysym == LEFT
			&& fractal->zoom < 0.5))
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if ((keysym == UP && fractal->zoom > 0.5) || (keysym == DOWN
			&& fractal->zoom < 0.5))
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if ((keysym == DOWN && fractal->zoom > 0.5) || (keysym == UP
			&& fractal->zoom < 0.5))
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keysym == C)
		fractal->rang = 0;
	else if (keysym == V)
		fractal->rang = 1;
	else if (keysym == P)
		fractal->max_iter += 10;
	else if (keysym == M)
		fractal->max_iter -= 10;
	else if (keysym == J)
	{
		if (fractal->julia_c < 6)
			fractal->julia_c++;
		else
			fractal->julia_c = 0;
	}
	else
	{
		return (0);
	}
	draw_fractal(fractal, fractal->name);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
}
