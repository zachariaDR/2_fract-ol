#include "fract_ol.h"

void    plotting_mandelbrot(t_fract *f)
{

    int     iterations;
    int     color;
    t_cmp   c;

    f->pixel_x = 0;
    while (f->pixel_x < f->width)
    {
        f->pixel_y = 0;
        while (f->pixel_y < f->heigth)
        {
            c = map_to_complex(f);                                                                      //checked
            iterations = is_in_mandelbrot_set(c, f->max_iter);                                          //checked
            color = map_to_color(iterations, f->max_iter);                                             
            my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, color);
            f->pixel_y++;
        }
        f->pixel_x++;
    }
    printf("\nDONE zoom = %f\n", f->zoom);
}

// i must start creat Julia one tonight
void    plotting_julia(t_fract *f)
{
    int     iterations;
    int     color;
    t_cmp   z;

    f->pixel_x = 0;
    while (f->pixel_x < f->width)
    {
        f->pixel_y = 0;
        while (f->pixel_y < f->heigth)
        {
;
            z = map_to_complex(f);                                                               //checked
            iterations = is_in_julia_set(f->cs[f->julia_c], z, f->max_iter);                     //checked
            color = map_to_color(iterations, f->max_iter);                                             
            my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, color);
            f->pixel_y++;
        }
        f->pixel_x++;
    }
    printf("\nc[%d] = %f + i%f\n", f->julia_c, f->cs[f->julia_c].re, f->cs[f->julia_c].im);
}

void    plotting_burnship(t_fract *f)
{

    int     iterations;
    int     color;
    t_cmp   c;

    f->pixel_x = 0;
    while (f->pixel_x < f->width)
    {
        f->pixel_y = 0;
        while (f->pixel_y < f->heigth)
        {
            c = map_to_complex(f);                                                                      //checked
            iterations = is_in_burnship_set(c, f->max_iter);                                          //checked
            color = map_to_color(iterations, f->max_iter);                                             
            my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, color);
            f->pixel_y++;
        }
        f->pixel_x++;
    }
    printf("\nlet them burn = %f\n", f->zoom);
}
