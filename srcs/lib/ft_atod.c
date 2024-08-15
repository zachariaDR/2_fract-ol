#include "fract_ol.h"

double	ft_atod(const char *str)
{
	double 	res;
	char 	*s;
	int 	dot;
	int 	mp;

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
			// printf(" before . res = %.2f\n", res);
			res += ft_after_dot(s, dot);
			// printf(" after . res = %.2f\n", res);
		}
		free(s);
	}
	return (res * mp);
}
