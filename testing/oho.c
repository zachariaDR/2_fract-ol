# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ha.h"

# define  INT_MIN_UD 2147483648

static int	ft_isspace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f'
		|| c == '\n');
}

static int is_nb(const char c)
{
	return (c >= '0' && c <= '9');
}

double	ft_atoi(const char *str, int *sign, int *dot)
{
	double 	res;
	int		i;
	// "-/+/eps|xxx|.|yyy"
	res = 0;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (str[0] == '-')
		*sign = -1;
	while (is_nb(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		*dot = 1;
	return (res);
}

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

int one_single_dot(const char *str)
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
	if ((dot < 2) && ((p == 1 && m == 0) || (p == 0 && m == 1) || (p == 0 && m == 0)))
		return (1);
	else
		return (0);
}

int only_nbs(const char *str)
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

int no_dublicates(const char *str)
{
	int i;
	char *soso;
	int dub;

	dub = 0;
	i = 0;
	soso = ft_strtrim(str, " ");
	if (!soso)
		return (-1);
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
	free(soso);
	return (1);
	//must free sexy soso
}

int str_is_valide(const char *str)
{
	if (only_nbs(str) && one_single_dot(str) && no_dublicates(str))
		return (1);
	return (0);
}

int valid_order(char *str)
{
	int i;
	int s;

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
	while (str[i])  ///   ".\0"
	{
		if (str[i] == '.')
		{
			// printf(" str[%d] = %c | str[%d] = %c \n", i-1, str[i-1], i+1, str[i+1]);
			if (!is_nb(str[i+1]) && !is_nb(str[i-1]))
				return (0);
		}
		i++;
	}
	return (1);	
}

// .37  |  13.37  |  13. : Passed
//+.37  | -13.37  | +13. : Passed

//  .-  : X
// +.  : X


double	ft_atod(char *str)
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
		s = ft_strtrim(str, " ");
		if (valid_order(s))
		{
			res = ft_atoi(s, &mp, &dot);
			printf(" before . res = %.2f\n", res);
			res += ft_after_dot(s, dot);
			printf(" after . res = %.2f\n", res);
		}
		free(s);
	}
	return (res * mp);
}

int main(void)
{

//  13
//  13. 
//  13.37
//  .37
//  13  .37    should not pass X

//  -13
//  -13.  
//  -13.0
//  -13.37
//  -.37

	double a;

	a = ft_atod(" - 3    ");
	printf("\n\na = %.2f \n", a);


    return (0);
}

