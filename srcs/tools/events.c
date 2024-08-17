/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:24:40 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/17 10:37:08 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_zoom(int button, int x, int y, t_fract *f)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (f->re_min + (f->re_max - f->re_min) * ((double)x / f->width))
		* f->zoom;
	mouse_im = (f->im_max - (f->im_max - f->im_min) * ((double)y / f->heigth))
		* f->zoom;
	if (button == 4)
		f->zoom *= 0.5;
	else if (button == 5)
		f->zoom *= 1.5;
	else
		return (0);
	f->shift_x += mouse_re - (f->re_min + (f->re_max - f->re_min) * ((double)x
				/ f->width)) * f->zoom;
	f->shift_y += mouse_im - (f->im_max - (f->im_max - f->im_min) * ((double)y
				/ f->heigth)) * f->zoom;
	draw_fractal(f, f->name);
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
	else if (keysym == C || keysym == V || keysym == P || keysym == M)
		change_colors(fractal, keysym);
	else if (keysym == J)
		change_julia(fractal);
	else if (keysym == L || keysym == K)
		change_limit(fractal, keysym);
	else
		return (0);
	draw_fractal(fractal, fractal->name);
	return (0);
}
