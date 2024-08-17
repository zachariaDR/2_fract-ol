/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:59:00 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/15 12:00:18 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	check_args(int ac, char **av)
{
	if (ac != 2 && ac != 4)
	{
		ft_putstr_fd("Mandelbrot & Tricorn Usage: ./fractol <mandel/tri>\n", 1);
		ft_putstr_fd("Julia Usage: ./fractol julia RE IM (RE & IM: Optional)\n",
			1);
		ft_putstr_fd("Available fractals:\n  --> Mandelbrot (aka mandel)", 1);
		ft_putstr_fd(":\n  --> Julia (aka julia)\n  --> Tricorn (aka tri)\n",
			1);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(av[1], "mandel", 7) && ft_strncmp(av[1], "julia", 6)
		&& ft_strncmp(av[1], "tri", 4))
		(ft_putstr_fd("Error: Unvalid Fractal!\n", 1), exit(EXIT_FAILURE));
	if (ac == 4 && ft_strncmp(av[1], "julia", 6))
		(ft_putstr_fd("Mandelbrot & Tricorn Usage: ./fractol <mandel/tri>\n",
				1), exit(EXIT_FAILURE));
	if (ac == 4 && ((ft_atod(av[2]) == 0.0 && ft_strncmp(av[2], "0", 1))
			|| (ft_atod(av[3]) == 0.0 && ft_strncmp(av[3], "0", 1))))
		(ft_putstr_fd("Error: Unvalid Julia complexe points\n", 1),
			exit(EXIT_FAILURE));
}
