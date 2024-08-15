#include "fract_ol.h"

int	no_dublicates(const char *str)
{
	int		i;
	char	*soso;
	int		dub;

	dub = 0;
	i = 0;
	soso = ft_strtrim(str, " \t\v\r\f\n");
	if (!soso)
		return (-1);
	while (soso[i])
	{
		if (!is_nb(soso[i]) && soso[i] != '.' && soso[i] != '+'
			&& soso[i] != '-')
		{
			return (0);
			break ;
		}
		i++;
	}
	free(soso);
	return (1);
}
