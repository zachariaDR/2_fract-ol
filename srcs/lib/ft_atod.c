/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:16:06 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/15 12:19:06 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	ft_atod(const char *str)
{
	double	res;
	char	*s;
	int		dot;
	int		mp;

	s = NULL;
	mp = 1;
	dot = 0;
	res = 0.0;
	if (str_is_valide(str))
	{
		s = ft_strtrim(str, " \t\v\r\f\n");
		if (valid_order(s))
		{
			res = ft_atoi(s, &mp, &dot);
			res += ft_after_dot(s, dot);
		}
		free(s);
	}
	return (res * mp);
}
