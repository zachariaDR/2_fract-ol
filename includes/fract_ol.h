/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:07:51 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/15 13:25:43 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

// # include "lib/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
# define L 107
# define K 108

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct complexe
{
	double	re;
	double	im;
}			t_cmp;

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr; // changed type her from char* to void*
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		color_shift;
	char	*name;
	double	zoom;
	double	re_max;
	double	re_min;
	double	im_max;
	double	im_min;
	int		max_iter;
	double	width;
	double	heigth;
	int		pixel_x;
	int		pixel_y;
	double	shift_x;
	double	shift_y;
	int		julia_c;
	int		li;
	int		rang;
	double	limit[7];
	t_cmp	cs[7];
}			t_fract;

// Fract-Ol Tools
void		put_color_to_pixel(t_fract *fractal, int x, int y, int color);
int			draw_fractal(t_fract *fractal, char *query);
void		plotting_mandelbrot(t_fract *f);
void		plotting_julia(t_fract *f);
void		plotting_burnship(t_fract *f);
void		plotting_tricorn(t_fract *f);
t_cmp		mandelbrot_function(t_cmp c, t_cmp z);
int			is_in_mandelbrot_set(t_fract *f, t_cmp c, int max_iter);
int			is_in_julia_set(t_fract *f, t_cmp c, t_cmp zi, int max_iter);
int			is_in_burnship_set(t_fract *f, t_cmp c, int max_iter);
int			is_in_tricorn_set(t_fract *f, t_cmp c, int max_iter);
t_cmp		map_to_complex(t_fract *f);
void		my_mlx_pixel_put(t_fract *data, int x, int y, int color);
int			map_to_color(int iterations, int max_iterations);
int			create_rgb(int r, int g, int b);
double		mod2_z(t_cmp z);
double		ft_abs(double a);
double		ft_pow(double x, int n);
void		set_z(t_cmp *z, double a, double b);
void		init_mlx(t_fract *fractal);
void		init_fract(t_fract *f, char *s, double re, double im);
void		init_z(t_cmp *z);
int			exit_fractal(t_fract *fractal);
void		change_julia(t_fract *fractal);
void		change_limit(t_fract *fractal, int key);
void		change_colors(t_fract *fractal, int key);
int			ft_zoom(int button, int x, int y, t_fract *f);
int			key_handler(int keysym, t_fract *fractal);
int			exit_fractal(t_fract *fractal);

// Checks
int			no_dublicates(const char *str);
int			one_single_dot(const char *str);
int			only_nbs(const char *str);
int			str_is_valide(const char *str);
int			valid_order(char *str);
void		check_args(int ac, char **av);

// Libft Tools
double		ft_atod(const char *str);
double		ft_atoi(const char *str, int *sign, int *dot);
double		ft_after_dot(const char *str, int dot);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strdup(const char *s1);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			is_nb(const char c);

#endif