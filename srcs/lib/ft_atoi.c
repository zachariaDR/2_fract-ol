/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:35:56 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/12 02:18:35 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"


static int	ft_isspace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f'
		|| c == '\n');
}

static int	skip(const char *str, size_t *index)
{
	int		sgn;
	size_t	i;

	i = 0;
	sgn = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	*index = i;
	return (sgn);
}

double	ft_atoi(const char *str, int *sign, int *error)
{
	double	res;
	size_t	i;

	res = 0;
	*sign = skip(str, &i);
    if (str[i] == '.' && (str[i+1] >= '0' && str[i+1] <= '9'))
	{
        *error = 0;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + (str[i] - '0');
        *error = 0;
		i++;
	}
	return  (res);  //(res * sign);
}

// fuc(str)
// {
// 	while()
// 	{
// 	if (str[i] = ' ' | str[i] == '\t')
// 		isspace++
// 	i++
// 	}
// 	return (isspace == i)
// }
// " 		  3 "
