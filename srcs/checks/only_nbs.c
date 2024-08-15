#include "fract_ol.h"

static int	ft_isspace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f'
		|| c == '\n');
}

int	only_nbs(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_nb(str[i]) && str[i] != '.' && !ft_isspace(str[i])
			&& str[i] != '+' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
