#include "fract_ol.h"

t_cmp	tricorn_function(t_cmp c, t_cmp z)
{
	t_cmp	zi;

	zi.re = (z.re * z.re) - (z.im * z.im) + c.re;
	zi.im = -2 * z.re * z.im + c.im;
	return (zi);
}

int	is_in_tricorn_set(t_cmp c, int max_iter)
{
	int		i;
	t_cmp	zi;

	i = 0;
	init_z(&zi);
	while (i < max_iter)
	{
		zi = tricorn_function(c, zi);
		if (mod2_z(zi) > 4)
			return (i);
		i++;
	}
	return (max_iter);
}

void	plotting_tricorn(t_fract *f)
{
	int iterations;
	t_cmp c;

	f->pixel_x = 0;
	while (f->pixel_x < f->width)
	{
		f->pixel_y = 0;
		while (f->pixel_y < f->heigth)
		{
			c = map_to_complex(f);                         
			iterations = is_in_tricorn_set(c, f->max_iter);
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