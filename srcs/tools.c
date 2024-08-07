#include "fract_ol.h"

void    init_z(t_cmp *z)
{
    z->re = 0;
    z->im = 0;
}

void	init_mlx(t_fract *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HIGHT, "Fract-ol");
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel,
			&fractal->line_length,
			&fractal->endian);
}

void    init_fract(t_fract *f, char *s)
{
    f->zoom = 1;
    f->shift_x = 0;
    f->shift_y = 0;
    f->heigth = 600;
    f->width = 800;
    f->re_max = 2.0;
    f->re_min = -2.0;
    f->im_max = 2;
    f->im_min = -2.0;
    f->max_iter = 42;
    f->julia_c = 0;
    f->name = s;
    set_z(&f->cs[0], -0.79, 0.15);
    set_z(&f->cs[1], -0.162, 1.04);
    set_z(&f->cs[2], 0.3, 0.01);
    set_z(&f->cs[3], -1.476, 0.0);
    set_z(&f->cs[4], -0.12, -0.77);
    set_z(&f->cs[5], 0.28, 0.008);
}


