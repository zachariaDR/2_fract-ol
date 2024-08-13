#include "fract_ol.h"

t_cmp    mandelbrot_function(t_cmp c, t_cmp z)
{
    t_cmp zi;

    zi.re = (z.re * z.re) - (z.im * z.im) + c.re;
    zi.im = 2*z.re*z.im + c.im;
    return (zi);
}

int	is_in_mandelbrot_set(t_cmp c, int max_iter)
{
	int		i;
	double	x_temp;
    t_cmp z;
    // t_cmp c;

	i = 0;
    init_z(&z);
	while (i < max_iter)
	{
		x_temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2. * z.re * z.im + c.im;
		z.re = x_temp;
        // z = mandelbrot_function(c, z);
		if (mod2_z(z) > __DBL_MAX__)
			return (i) ;
        i++;
	}
    return (max_iter);
}

void    plotting_mandelbrot(t_fract *f)
{

    int     iterations;
    // int     rang;
    // int     color;
    t_cmp   c;

    f->pixel_x = 0;
    while (f->pixel_x < f->width)
    {
        f->pixel_y = 0;
        while (f->pixel_y < f->heigth)
        {
	        c = map_to_complex(f);                                                                         //checked                                          //checked
            iterations = is_in_mandelbrot_set(c, f->max_iter);                                             //checked
            f->color = map_to_color(iterations, f->max_iter);                                             
            if (f->rang)
		        my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, f->color);
            else
		        my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, f->color * iterations);
            f->pixel_y++;
        }
        f->pixel_x++;
    }
}