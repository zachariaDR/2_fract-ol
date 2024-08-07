/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:07:51 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/07 13:36:46 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # include "lib/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include <X11/X.h>
# include <X11/keysym.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# define WIDTH 800
# define HIGHT 600
// KEYCODES
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 114
# define C 99
# define H 104
# define J 106
# define P 112
# define M 109

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
    char   *addr;
    int    bits_per_pixel;
    int    line_length;
    int    endian;
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
    t_cmp  cs[6];
}               t_fract;

// Fract-Ol Tools
int	    draw_fractal(t_fract *fractal, char *query);
void    plotting_mandelbrot(t_fract *f);
void    plotting_julia(t_fract *f);
void    plotting_burnship(t_fract *f);
t_cmp   map_to_complex(t_fract * f);
int     is_in_mandelbrot_set(t_cmp c, int max_iter);
int     is_in_julia_set(t_cmp c, t_cmp zi, int max_iter);
int     is_in_burnship_set(t_cmp c, int max_iter);
t_cmp   mandelbrot_function(t_cmp c, t_cmp z);
void    my_mlx_pixel_put(t_fract *data, int x, int y, int color);
int     map_to_color(int iterations, int max_iterations);
int     create_rgb(int r, int g, int b);
int     mod2_z(t_cmp z);
double  ft_abs(double a);
int     ft_pow(int x, int n);
void    set_z(t_cmp *z, double a, double b);
void	init_mlx(t_fract *fractal);
void    init_fract(t_fract *f, char *s);
void    init_z(t_cmp *z);
int	    exit_fractal(t_fract *fractal);

int ft_zoom(int button, int x, int y, t_fract *f);
int	key_handler(int keysym, t_fract *fractal);


// Libft Tools
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);

#endif