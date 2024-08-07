#include "fract_ol.h"





// t_cmp map_to_complex(t_fract *f)
// {
//     t_cmp z;
//     z.re = f->re_min + (f->re_max - f->re_min) * ((double)(f->pixel_x) / f->width) + f->shift_x;
//     z.im = f->im_max - (f->im_max - f->im_min) * ((double)(f->pixel_y) / f->heigth) + f->shift_y;
//     return (z);
// }

// void    plotting_mandelbrot(t_fract *f)
// {

//     int     iterations;
//     int     color;
//     t_cmp   c;

//     f->pixel_x = 0;
//     while (f->pixel_x < f->width)
//     {
//         f->pixel_y = 0;
//         while (f->pixel_y < f->heigth)
//         {
//             c = map_to_complex(f);                                                                      //checked
//             iterations = is_in_mandelbrot_set(c, f->max_iter);                                          //checked
//             color = map_to_color(iterations, f->max_iter);                                             
//             //draw_pixel(x, y, color);
//             my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, color);
//             f->pixel_y++;
//         }
//         f->pixel_x++;
//     }
//     printf("\nDONE zoom = %f\n", f->zoom);
// }

//---------------------------------------------------------------------------------------------------------------------------------------

// int ft_zoom(int button, int x, int y, t_fract *f)
// {
//     t_cmp m;
//     // double nre_max;
//     // double nre_min;
//     // double nim_max;
//     // double nim_min;
//     m.re = (f->re_min + (f->re_max - f->re_min) * ((double)x / f->width)) ;
//     m.im = (f->im_max - (f->im_max - f->im_min) * ((double)y / f->heigth));
//     // m.re = (f->re_min + (f->re_max - f->re_min) * ((float)x / f->width)) * f->zoom;
//     // m.im = (f->im_max - (f->im_max - f->im_min) * ((float)y / f->heigth)) * f->zoom;


//     if (button == 4)
//     {
//         (f->zoom) = 0.75; //*= 0.75;
//         // f->shift_x += (nre_min + (nre_max - nre_min) * ((float)x / f->width))  * 1;
//         // f->shift_y += (nim_max - (nim_max - nim_min) * ((float)y / f->heigth)) * 1;
//         f->shift_x += m.re -( f->re_min + (f->re_max - f->re_min) * ((float)x / f->width)) * f->zoom;
//         f->shift_y += m.im -( f->im_max - (f->im_max - f->im_min) * ((float)y / f->heigth)) * f->zoom;
//     }
//     else if (button == 5)
//     {
//         (f->zoom) = 1.25; //*= 1.25
//         f->shift_x += m.re - (f->re_min + (f->re_max - f->re_min) * ((float)x / f->width)) * f->zoom ;
//         f->shift_y += m.im - (f->im_max - (f->im_max - f->im_min) * ((float)y / f->heigth)) * f->zoom ;
//     }
//     else
//         return (0);

//     plotting_mandelbrot(f);
//     mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
//     return (0); 
// }


// int ft_zoom(int button, int x, int y, t_fract *f)
// {
//     double zoom_factor;
//     double mouse_re, mouse_im;

//     // Convert mouse coordinates to complex plane coordinates
//     mouse_re = f->re_min + (f->re_max - f->re_min) * ((double)x / f->width);
//     mouse_im = f->im_max - (f->im_max - f->im_min) * ((double)y / f->heigth);

//     if (button == 4) // Zoom in
//     {
//         zoom_factor = 0.9; // Zoom in by 10%
//     }
//     else if (button == 5) // Zoom out
//     {
//         zoom_factor = 1.1; // Zoom out by 10%
//     }
//     else
//     {
//         return 0; // If it's not a zoom event, do nothing
//     }

//     // Adjust the boundaries while keeping the mouse position fixed
//     f->re_min = mouse_re + (f->re_min - mouse_re) * zoom_factor;
//     f->re_max = mouse_re + (f->re_max - mouse_re) * zoom_factor;
//     f->im_min = mouse_im + (f->im_min - mouse_im) * zoom_factor;
//     f->im_max = mouse_im + (f->im_max - mouse_im) * zoom_factor;

//     // Update the zoom level
//     f->zoom *= zoom_factor;

//     // Redraw the fractal
//     plotting_mandelbrot(f);
//     mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);

//     return 0;
// }

int ft_zoom(int button, int x, int y, t_fract *f)
{
    // double zoom_factor;
    double mouse_re, mouse_im;

    // Convert mouse coordinates to complex plane coordinates
    mouse_re = (f->re_min + (f->re_max - f->re_min) * ((double)x / f->width)) * f->zoom;
    mouse_im = (f->im_max - (f->im_max - f->im_min) * ((double)y / f->heigth)) * f->zoom;

    if (button == 4) // Zoom in
    {
        f->zoom *= 0.9; // Zoom in by 10%
    }
    else if (button == 5) // Zoom out
    {
        f->zoom *= 1.1; // Zoom out by 10%
    }
    else
    {
        return 0; // If it's not a zoom event, do nothing
    }

    // Update the zoom level
    // f->zoom *= zoom_factor;

    // Adjust the shift to keep the mouse position fixed
    f->shift_x += mouse_re - (f->re_min + (f->re_max - f->re_min) * ((double)x / f->width)) * f->zoom;
    f->shift_y += mouse_im - (f->im_max - (f->im_max - f->im_min) * ((double)y / f->heigth)) * f->zoom;
    // Redraw the fractal
    draw_fractal(f, f->name);
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
    return (0);
}

int	key_handler(int keysym, t_fract *fractal)
{
	if (keysym == ESC)
		exit(EXIT_SUCCESS);
	else if ((keysym == LEFT && fractal->zoom > 0.5) || (keysym == RIGHT && fractal->zoom < 0.5))
        fractal->shift_x += 0.5 * fractal->zoom;
	else if ((keysym == RIGHT && fractal->zoom > 0.5) || (keysym == LEFT && fractal->zoom < 0.5))
		fractal->shift_x -= 0.5 * fractal->zoom;	
	else if ((keysym == UP && fractal->zoom > 0.5) || (keysym == DOWN && fractal->zoom < 0.5))
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if ((keysym == DOWN && fractal->zoom > 0.5) || (keysym == UP && fractal->zoom < 0.5))
		fractal->shift_y += 0.5 * fractal->zoom;	
	else if (keysym == P)
		fractal->iter += 10;
	else if (keysym == M)	
		fractal->iter -= 10;
    else if (keysym == J)
    {
        if (fractal->julia_c < 5)
		    fractal->julia_c++;
        else
            fractal->julia_c = 0;
    }
    else
    {
        return (0);
    }
	draw_fractal(fractal, fractal->name);
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
}

// int main(void)
// {

//     t_fract *fract;

//     fract = malloc(sizeof(t_fract));
//     init_fract(fract);
//     fract->mlx = mlx_init();
//     fract->win = mlx_new_window(fract->mlx, 800, 600, "Fract-ol");
//     fract->img = mlx_new_image(fract->mlx, 800, 600);
//     fract->addr = mlx_get_data_addr(fract->img, &(fract->bits_per_pixel), &(fract->line_length), &(fract->endian));
//     mlx_key_hook(fract->win, key_handler, fract);
//     mlx_mouse_hook(fract->win, ft_zoom, fract);
//     // Here you would loop through your pixels and call my_mlx_pixel_put
//     // For example:
//     //my_mlx_pixel_put(&img, 400, 300, 0x00FF0000);  // Draws a red pixel at (5,5)
//    // plotting_mandelbrot(img, 800, 600, -2, 1, -1, 1, 42);
//     plotting_mandelbrot(fract);
//     mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
//     mlx_loop(fract->mlx);
// }
