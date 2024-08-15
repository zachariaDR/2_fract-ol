

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
//         return (0); // If it's not a zoom event, do nothing
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

//     return (0);
// }
