/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:35:56 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/14 16:54:07 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	ft_atoi(const char *str, int *sign, int *dot)
{
	double 	res;
	int		i;
	// "-/+/eps|xxx|.|yyy"
	res = 0;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (str[0] == '-')
		*sign = -1;
	while (is_nb(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		*dot = 1;
	return (res);
}
