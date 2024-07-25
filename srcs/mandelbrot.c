#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>

typedef struct complexe
{
    double re;
    double im;
}           t_cmp;

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_data;

void    init_z(t_cmp *z)
{
    z->re = 0;
    z->im = 0;
}

void    set_z(t_cmp *z, int a, int b)
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
int abs2_z(t_cmp z)
{
    // |z|   = sqrt(a^2 + b^2)
    // |z|^2 = (a^2 + b^2)^2
    //       =  a^4 + 2.a^2.b^2 + b^4
    return (ft_pow(z.re, 4) + ft_pow(z.im, 4) + (2*ft_pow(z.re, 2)*ft_pow(z.im, 2)));
}

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

int     is_in_mandelbrot_set(t_cmp c, int max_iter)
{
    int i;
    t_cmp zi;

    i = 0;
    init_z(&zi);
    while (i < max_iter)
    {
        //printf("f(%d) = ", zi.re + zi.im);
        zi = mandelbrot_function(c, zi);
        //printf("%d \n", zi.im+zi.re);
        if (abs2_z(zi) > 4)
            return (i);
        i++;
    }
    return (max_iter);
}

t_cmp   map_to_complex(int pixel_x, int pixel_y, int width, int height, double min_real, double max_real, double min_imag, double max_imag)
{
    t_cmp z;

    z.re = min_real + (max_real - min_real) * ((float)pixel_x / width);
    z.im = max_imag - (max_imag - min_imag) * ((float)pixel_y / height);
    return (z);
}

// for each pixel_y from 0 to height:
//     for each pixel_x from 0 to width:
//         c = map_to_complex(pixel_x, pixel_y, width, height, min_real, max_real, min_imag, max_imag)
//         iterations = calculate_mandelbrot(c, max_iterations)
//         color = map_iterations_to_color(iterations, max_iterations)
//         draw_pixel(pixel_x, pixel_y, color)

// t_color map_to_color(int iterations, int max_iterations) {
//     if (iterations == max_iterations) {
//         return (t_color){0, 0, 0};  // Black for points in the set
//     }
//     return palette[iterations % 16];
// }

int create_rgb(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

int map_to_color(int iterations, int max_iterations)
{
    if (iterations == max_iterations)
        return (0);  // Black for points in the set
    
    float t = (float)iterations / max_iterations;
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    
    return create_rgb(r, g, b);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    plotting_mandelbrot(t_data img, int width, int height, double min_real, double max_real, double min_imag, double max_imag, int max_iter)
{
    int     x;
    int     y;
    int     iterations;
    int     color;
    t_cmp   c;

    x = 0;
    while (x < width)
    {
        y = 0;
        while (y < height)
        {
            c = map_to_complex(x, y, width, height, min_real, max_real, min_imag, max_imag);         //checked
            iterations = is_in_mandelbrot_set(c, max_iter);                                          //checked
            color = map_to_color(iterations, max_iter);                                             
            //draw_pixel(x, y, color);
            my_mlx_pixel_put(&img, x, y, color);
            y++;
        }
        x++;
    }
}


int main(void)
{

    // t_cmp a;

    // set_z(&a, 0, 1);

    // if (is_in_mandelbrot_set(a, 1000) == 1000)
    //     printf("C = %d + i%d is in Mandelbrot !!\n", a.re, a.im);
    // else
    //     printf("C = %d + i%d is in Not in Mandelbrot !!\n", a.re, a.im);

    // map_to_complex(0, 0, 800, 600, -2, 1, -1, 1);          //-2-1i to 1+1i.

    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "Fract-ol");
    img.img = mlx_new_image(mlx, 800, 600);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // Here you would loop through your pixels and call my_mlx_pixel_put
    // For example:
    //my_mlx_pixel_put(&img, 400, 300, 0x00FF0000);  // Draws a red pixel at (5,5)
   plotting_mandelbrot(img, 800, 600, -2, 1, -1, 1, 1000);
   // plotting_mandelbrot(img, 800, 600, -2.0, 1.0, -1.5, 1.5, 1000);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    
    mlx_loop(mlx);

}