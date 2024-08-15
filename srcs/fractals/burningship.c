#include "fract_ol.h"

t_cmp	burnship_function(t_cmp c, t_cmp z)
{
	t_cmp	zi;

	zi.re = (z.re * z.re) - (z.im * z.im) + c.re;
	zi.im = ft_abs(2.0 * z.re * z.im) + c.im;
	return (zi);
}

int	is_in_burnship_set(t_cmp c, int max_iter)
{
	int		i;
	t_cmp	zi;

	i = 0;
	init_z(&zi);
	while (i < max_iter)
	{
		zi = burnship_function(c, zi);
		if (mod2_z(zi) > 4)
			return (i);
		i++;
	}
	return (max_iter);
}

void	plotting_burnship(t_fract *f)
{
	int iterations;
	int color;
	t_cmp c;

	f->pixel_x = 0;
	while (f->pixel_x < f->width)
	{
		f->pixel_y = 0;
		while (f->pixel_y < f->heigth)
		{
			c = map_to_complex(f);
			iterations = is_in_burnship_set(c, f->max_iter);
			color = map_to_color(iterations, f->max_iter);
			my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, color);
			f->pixel_y++;
		}
		f->pixel_x++;
	}
}