#include "fract_ol.h"

void	set_z(t_cmp *z, double a, double b)
{
	z->re = a;
	z->im = b;
}

double	ft_pow(double x, int n)
{
	if (n == 2)
		return (x * x);
	if (n == 4)
		return (x * x * x * x);
	else
		return (0);
}

double	mod2_z(t_cmp z)
{
	return (z.re * z.re + z.im * z.im);
}

double	ft_abs(double a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

t_cmp	map_to_complex(t_fract *f)
{
	t_cmp	z;

	z.re = (f->re_min + (f->re_max - f->re_min) * ((float)(f->pixel_x) / f->width)) * f->zoom + f->shift_x;
	z.im = (f->im_max - (f->im_max - f->im_min) * ((float)(f->pixel_y) / f->heigth)) * f->zoom + f->shift_y;
	return (z);
}
