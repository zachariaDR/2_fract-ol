#include "fract_ol.h"

int	valid_order(char *str)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	if (str[0] == '+' || str[i] == '-')
		s = 1;
	while (str[i] && s == 0)
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	if (str[0] == '.' && !is_nb(str[1]))
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (!is_nb(str[i + 1]) && !is_nb(str[i - 1]))
				return (0);
		}
		i++;
	}
	return (1);
}
