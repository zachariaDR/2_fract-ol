#include "fract_ol.h"

static int	ft_isspace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f'
		|| c == '\n');
}

static void	skip_rev(const char *str, size_t *index)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		i--;
	*index = i;
}

double after_dot(const char *str)
{
    double	res;
	size_t	i;

	res = 0.0;
	skip_rev(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res / 10) + (str[i] - '0');
		i--;
	}
    if (str[i] == '.')
	    res /= 10;
    else
        res = 0.0;
    return (res);
}
