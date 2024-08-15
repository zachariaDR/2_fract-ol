#include "fract_ol.h"

double	ft_after_dot(const char *str, int dot)
{
	double 	res;
	int		i;
	// "-/+/eps|xxx|.|yyy"
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
