#include "fract_ol.h"

void    set_z(t_cmp *z, double a, double b)
{
    z->re = a;
    z->im = b;
}

int     ft_pow(int x, int n)
{
    if (n == 2)
        return (x * x);
    if (n == 4)
        return (x * x * x * x);
    else
        return (0);
}

int mod2_z(t_cmp z)
{
    // |z|   = sqrt(a^2 + b^2)
    // |z|^2 = (a^2 + b^2)^2
    //       =  a^4 + 2.a^2.b^2 + b^4
    return (ft_pow(z.re, 4) + ft_pow(z.im, 4) + (2*ft_pow(z.re, 2)*ft_pow(z.im, 2)));
}

double ft_abs(double a)
{
    if (a < 0)
        return (a*-1);
    return (a);
}
t_cmp   map_to_complex(t_fract * f)
{
    t_cmp z;

    z.re = (f->re_min + (f->re_max - f->re_min) * ((float)(f->pixel_x) / f->width))  * f->zoom + f->shift_x;
    z.im = (f->im_max - (f->im_max - f->im_min) * ((float)(f->pixel_y) / f->heigth)) * f->zoom + f->shift_y;

    return (z);
}
