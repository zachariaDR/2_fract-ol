#include "fract_ol.h"

t_cmp    mandelbrot_function(t_cmp c, t_cmp z)
{
    t_cmp zi;

    //f(z) =  z^2 + c
    //z^2  =  a^2 - b^2 + i(2ab)
    //z^2  -> re = a^2 - b^2  |  im = 2ab

    zi.re = (z.re * z.re) - (z.im * z.im) + c.re;
    zi.im = 2*z.re*z.im + c.im;
    return (zi);
}

t_cmp    burnship_function(t_cmp c, t_cmp z)
{
    t_cmp zi;

    //f(z) =  (|re| + i |im|)^2 + c
    //|z|^2  =  | a^2 - b^2| + i |2ab|
    //z^2  -> re = a^2 - b^2  |  im = 2ab

    zi.re = (z.re * z.re) - (z.im * z.im) + c.re;
    zi.im = ft_abs(2.0*z.re*z.im) + c.im;
    // zi.im = 2*ft_abs(z.re)*ft_abs(z.im) + c.im;
    return (zi);
}

int     is_in_mandelbrot_set(t_cmp c, int max_iter)
{
    int i;
    t_cmp zi;

    i = 0;
    init_z(&zi);
    while (i < max_iter)
    {
        zi = mandelbrot_function(c, zi);
        if (mod2_z(zi) > 4)
            return (i);
        i++;
    }
    return (max_iter);
}

int     is_in_burnship_set(t_cmp c, int max_iter)
{
    int i;
    t_cmp zi;

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

int     is_in_julia_set(t_cmp c, t_cmp zi, int max_iter)
{
    int i;

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