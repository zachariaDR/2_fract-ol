#include "fract_ol.h"

int	is_in_julia_set(t_cmp c, t_cmp zi, int max_iter)
{
	int	i;

	i = 0;
	while (i < max_iter)
	{
		zi = mandelbrot_function(c, zi);
		if (mod2_z(zi) > 4)
			return (i);
		i++;
	}
	return (max_iter);
}

void	plotting_julia(t_fract *f)
{
	int iterations;
	int color;
	t_cmp z;

	f->pixel_x = 0;
	while (f->pixel_x < f->width)
	{
		f->pixel_y = 0;
		while (f->pixel_y < f->heigth)
		{
			z = map_to_complex(f);                                          
			iterations = is_in_julia_set(f->cs[f->julia_c], z, f->max_iter);
			color = map_to_color(iterations, f->max_iter);
			my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, color);
			f->pixel_y++;
		}
		f->pixel_x++;
	}
}