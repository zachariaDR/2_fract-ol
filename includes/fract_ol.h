/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:07:51 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/12 02:13:01 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # include "lib/libft.h"
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <pthread.h>
# include <X11/X.h>
# include <X11/keysym.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# define WIDTH 700
# define HIGHT 700
// KEYCODES
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 114
# define C 99
# define V 118
# define H 104
# define J 106
# define P 112
# define M 109

# define INT_MIN_UD 2147483648

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct complexe
{
    double re;
    double im;
}           t_cmp;


typedef struct s_fract
{
    void   *mlx;
    void   *win;
    void   *img;
    void   *addr;   //changed type her from char* to void*
    int    bits_per_pixel;
    int    line_length;
    int    endian;
    int    color;
    int    color_shift;
    char   *name;
    double zoom;
    double re_max;
    double re_min;
    double im_max;
    double im_min;
    int    max_iter;
    double width;
    double heigth;
    int    pixel_x;
    int    pixel_y;
    double shift_x;
    double shift_y;
    int    iter;
    int    julia_c;
    int    rang;
    t_cmp  cs[7];
}               t_fract;

// Fract-Ol Tools
void	put_color_to_pixel(t_fract *fractal, int x, int y, int color);

int	    draw_fractal(t_fract *fractal, char *query);
void    plotting_mandelbrot(t_fract *f);
void    plotting_julia(t_fract *f);
void    plotting_burnship(t_fract *f);
void    plotting_tricorn(t_fract *f);
t_cmp   mandelbrot_function(t_cmp c, t_cmp z);
int     is_in_mandelbrot_set(t_cmp c, int max_iter);
int     is_in_julia_set(t_cmp c, t_cmp zi, int max_iter);
int     is_in_burnship_set(t_cmp c, int max_iter);
int     is_in_tricorn_set(t_cmp c, int max_iter);
t_cmp   map_to_complex(t_fract * f);
void    my_mlx_pixel_put(t_fract *data, int x, int y, int color);
int     map_to_color(int iterations, int max_iterations);
int     create_rgb(int r, int g, int b);
double     mod2_z(t_cmp z);
double  ft_abs(double a);
double  ft_pow(double x, int n);
void    set_z(t_cmp *z, double a, double b);
void	init_mlx(t_fract *fractal);
// void    init_fract(t_fract *f, char *s);
void    init_fract(t_fract *f, char *s, double re, double im);
void    init_z(t_cmp *z);
int	    exit_fractal(t_fract *fractal);

int ft_zoom(int button, int x, int y, t_fract *f);
int	key_handler(int keysym, t_fract *fractal);


// Libft Tools
double  ft_atod(const char *str);
double	ft_atoi(const char *str, int *sign, int *error);
double  after_dot(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

#endif