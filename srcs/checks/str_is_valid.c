#include "fract_ol.h"

int	str_is_valide(const char *str)
{
	if (only_nbs(str) && one_single_dot(str) && no_dublicates(str))
		return (1);
	return (0);
}
