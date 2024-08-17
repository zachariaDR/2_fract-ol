/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:01:57 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/15 12:15:04 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	valid_order(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (str[0] == '+' || str[i] == '-')
		sign = 1;
	while (str[i] && sign == 0)
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	if (str[0] == '.' && !is_nb(str[1]))
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && (!is_nb(str[i + 1]) && !is_nb(str[i - 1])))
			return (0);
		i++;
	}
	return (1);
}
