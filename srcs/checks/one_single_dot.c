#include "fract_ol.h"

int	one_single_dot(const char *str)
{
	int	i;
	int	dot;
	int	p;
	int	m;

	i = 0;
	dot = 0;
	p = 0;
	m = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		if (str[i] == '+')
			p++;
		if (str[i] == '-')
			m++;
		i++;
	}
	if ((dot < 2) && ((p == 1 && m == 0) || (p == 0 && m == 1) || (p == 0
				&& m == 0)))
		return (1);
	else
		return (0);
}
