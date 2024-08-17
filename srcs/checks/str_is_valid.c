/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:01:48 by zadriouc          #+#    #+#             */
/*   Updated: 2024/08/15 12:01:53 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	str_is_valide(const char *str)
{
	if (only_nbs(str) && one_single_dot(str) && no_dublicates(str))
		return (1);
	return (0);
}
