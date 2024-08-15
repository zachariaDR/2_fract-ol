#include "fract_ol.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

// int map_to_color(int iterations, int max_iterations)
// {
//     if (iterations == max_iterations)
//         return (0);  // Black for points in the set

//     float t = (float)iterations / max_iterations;
//     int r = (int)(1 * (1 - t) * t * t * t * 255);
//     int g = (int)(1 * (1 - t) * (1 - t) * t * t * 255);
//     int b = (int)(1 * (1 - t) * (1 - t) * (1 - t) * t * 255);

//     return (create_rgb(r, g, b));
// }

int	map_to_color(int iterations, int max_iterations)
{
	float	t;
	int		r;
	int		g;
	int		b;

	if (iterations == max_iterations)
		return (0); // Black for points in the set
	t = (float)iterations / max_iterations;
	r = (int)(9 * (1 - t) * t * t * t * 255) + 0;
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255) + 0;
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255) + 0;

	return (create_rgb(r, g, b));
}

void	my_mlx_pixel_put(t_fract *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_color_to_pixel(t_fract *fractal, int x, int y, int color)
{
	int *buffer;

	buffer = fractal->addr;
	buffer[(y * fractal->line_length / 4) + x] = color;
}