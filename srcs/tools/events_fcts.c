/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:51:44 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/15 14:28:54 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	exit_fractal(t_fract *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(EXIT_SUCCESS);
	return (0);
}

void	change_julia(t_fract *fractal)
{
	if (fractal->julia_c < 6)
		fractal->julia_c++;
	else
		fractal->julia_c = 0;
}

void	change_limit(t_fract *fractal, int key)
{
	if (key == L)
	{
		if (fractal->li < 5)
			fractal->li++;
	}
	else if (key == K)
	{
		if (fractal->li > 0)
			fractal->li--;
	}
}

void	change_colors(t_fract *fractal, int key)
{
	if (key == C)
		fractal->rang = 0;
	else if (key == V)
		fractal->rang = 1;
	else if (key == P)
		fractal->max_iter += 10;
	else if (key == M)
		fractal->max_iter -= 10;
}
