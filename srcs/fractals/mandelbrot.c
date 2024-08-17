/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:21:20 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/15 14:55:23 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_cmp	mandelbrot_function(t_cmp c, t_cmp z)
{
	t_cmp	zi;

	zi.re = (z.re * z.re) - (z.im * z.im) + c.re;
	zi.im = 2 * z.re * z.im + c.im;
	return (zi);
}

int	is_in_mandelbrot_set(t_fract *f, t_cmp c, int max_iter)
{
	int		i;
	t_cmp	z;

	i = 0;
	init_z(&z);
	while (i < max_iter)
	{
		z = mandelbrot_function(c, z);
		if (mod2_z(z) > f->limit[f->li])
			return (i);
		i++;
	}
	return (max_iter);
}

void	plotting_mandelbrot(t_fract *f)
{
	int		iterations;
	t_cmp	c;

	f->pixel_x = 0;
	while (f->pixel_x < f->width)
	{
		f->pixel_y = 0;
		while (f->pixel_y < f->heigth)
		{
			c = map_to_complex(f);
			iterations = is_in_mandelbrot_set(f, c, f->max_iter);
			f->color = map_to_color(iterations, f->max_iter);
			if (f->rang)
				my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, f->color);
			else
				my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, f->color
					* iterations);
			f->pixel_y++;
		}
		f->pixel_x++;
	}
}
