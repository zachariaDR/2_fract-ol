/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_after_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:16:01 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/15 12:18:40 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	ft_after_dot(const char *str, int dot)
{
	double	res;
	int		i;

	res = 0;
	if (dot == 0)
		return (0.0);
	i = ft_strlen(str) - 1;
	while (is_nb(str[i]))
	{
		res = (res / 10) + (str[i] - '0');
		i--;
	}
	res /= 10;
	return (res);
}
