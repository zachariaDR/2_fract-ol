#include "fract_ol.h"

int one_single_dot(char *str)
{
	int i;
	int dot;
	int p;
	int m;

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
	if (dot < 2 && (p == 1 && m == 0) || (p == 0 && m == 1) || (p == 0 && m == 0))
		return (1);
	else
		return (0);
}

int only_nbs(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!is_nb(str[i]) && str[i] != '.' && !ft_isspace(str[i]) && str[i] != '+' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int no_dublicates(char *str)
{
	int i;
	char *soso;
	int dub;

	dub = 0;
	i = 0;
	soso = ft_strtrim(str, " ");
	printf("sexy soso : |%s| \n", soso);
	while (soso[i])
	{
		if (!is_nb(soso[i]) && soso[i]!= '.' && soso[i] != '+' && soso[i] != '-')
		{
			return (0);
			break;
		} 
		i++;
	}
	return (1);
}

void is_str_valide(char *str)
{
	if (only_nbs(str) && one_single_dot(str) && no_dublicates(str))
	{
		printf("Valid!\n");
	}
	else
		printf("Not valid!\n");
}

int valid_order(char *str)
{
	int i;

	i = 0;

	if (str[0] == '+' || str[i] == '-')
		i = 1;
	while (str[i] && i == 0)
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (!is_nb(str[i+1]))
				return (0);
		}
		i++;
	}
	return (1);	
}

double  ft_atod(const char *str)
{
    int     error;
    int     sign;
    double  res;

    error = 1;
    res = ft_atoi(str, &sign, &error);
    if (error)
        return (0.0);
    res += after_dot(str);
    res = res * sign;
    return (res);
}