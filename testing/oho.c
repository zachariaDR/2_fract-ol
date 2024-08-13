# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ha.h"

# define  INT_MIN_UD 2147483648

// int ft_strlen(const char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//         i++;
//     return (i);
// }

static int	ft_isspace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f'
		|| c == '\n');
}

static int is_nb(const char c)
{
	return (c >= '0' && c <= '9');
}
static int	skip(const char *str, size_t *index)
{
	int		sgn;
	size_t	i;

	i = 0;
	sgn = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	*index = i;
	return (sgn);
}

double	ft_atoi(const char *str, int *sign, int *error)
{
	double	res;
	size_t	i;

	res = 0;
	*sign = skip(str, &i);
    // if (str[i] == '.' && (str[i+1] >= '0' && str[i+1] <= '9'))
	// {
    //     *error = 0;
	// }
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
        *error = 0;
		i++;
	}
    if (str[i] != '.' && str[i] != 32)
        return (0.0);
	return  (res);  //(res * sign);
}

static void	skip_rev(const char *str, size_t *index)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		i--;
	*index = i;
}

// double after_dot(const char *str, int b_exist)
// {
//     double	res;
//     int     a_exist;
// 	size_t	i;

// 	res = 0.0;
//     a_exist = 0;
// 	skip_rev(str, &i);
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
//         a_exist = 1;
// 		res = (res / 10) + (str[i] - '0');
// 		i--;
// 	}
//     //if (str[i] == '.' && ((str[i-1] == 32 && b_exist == 1) || (str[i-1] >= '0' && str[i-1] <= '9')))
//     if (str[i] == '.' && (b_exist == 0 && ((str[i-1] >= '0' && str[i-1] <= '9')) || (b_exist == 1 && str[i-1] == 32)))
// 	    res /= 10;
//     else
//         res = 0.0;
//     return (res);
// }

double after_dot(const char *str, int b_exist)
{
    double	res;
    int     a_exist;
	size_t	i;

	res = 0.0;
    a_exist = 0;
	skip_rev(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
        a_exist = 1;
		res = (res / 10) + (str[i] - '0');
		i--;
	}
    //if (str[i] == '.' && ((str[i-1] == 32 && b_exist == 1) || (str[i-1] >= '0' && str[i-1] <= '9')))
    if (str[i] == '.' && (b_exist == 0 && ((str[i-1] >= '0' && str[i-1] <= '9')) || (b_exist == 1 && str[i-1] == 32)))
	    res /= 10;
    else
        res = 0.0;
    return (res);
}



// int valid_num(char *str)
// {
//     int i;

//     i = 0;
//     while (ft_isspace(str[i]))
//         i++;
//     while ((str[i-1] >= '0' && str[i-1] <= '9'))
//     {
//         i++;
//     }
//     if (str[i] == '.')
//         i++;
//     while ((str[i-1] >= '0' && str[i-1] <= '9'))
//     {
//         i++;
//     }
//     return (42);
// }

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
	// printf("dot == %d\n", dot);
	// printf("+ == %d\n", p);
	// printf("- == %d\n", m);
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
			if (!is_nb(str[i+1]) && (i != 0 && !is_nb(str[i-1])))
				return (0);
		}
		i++;
	}
	return (1);	
}

// .37  |  13.37  |  13 : Passed
//+.37  | -13.37  | +13 : Passed

//  .  : X
// +.  : X

double  ft_atod(const char *str)
{
    int     error;
    int     sign;
    double  res;
	char 	*s;

	if (!str_is_valide(str) || !valid_order("ft_trdsiimstr"))
		return (-1);
	// some logic + review atoi and after dot
    error = 1;
    res = ft_atoi(str, &sign, &error);
    if (error)
        return (0.0);
    res += after_dot(str, error);
    res = res * sign;
    return (res);
}

int main(void)
{

    // double b;
	// if (one_single_dot(str) == 1)
	// {
	// 	printf("one signle dot here: %s\n", str);
	// 	printf("func : %d\n", one_single_dot(str));
	// }
	// else
	// 	printf("there imposters here : %s\n", str);

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


	char *str = "   .    ";

	if (str_is_valide(str) == 1)
		printf("\"%s\" : str is VALID (1)\n", str);
	else
		printf("\"%s\" : str is NOT valid (STOP)\n", str);
	char *soso = ft_strtrim(str, " ");
	if (valid_order(soso) == 1 && str_is_valide(str))
	{
		printf("\"%s\"     : order is VALID (2)\n", soso);
		printf("YOU CAN PASS TO ITOD now!\n");
	}
	else if (str_is_valide(str))
		printf("\"%s\"     : order is NOT valid (STOP)\n", soso);

	// a = ft_atod("   .1337.4242   ");
	// if (a == -1)
	// 	printf("was not valid\n");
	// else
	// 	printf("success a == %f\n", a);

	// is_str_valide("   +1337.4242   ");
	// if (valid_order("-.37"))
	// 	printf("order -> VALID\n");
	// else
	// 	printf("order -> NOT Valid\n");

    // valid_double("  13 .42  ");
    //printf ("a = %f \n", a);
    // b = ft_atod("   ^     42.1337           ");
    // b += a;
    // printf("b = %f \n", b);

    return (0);
}

