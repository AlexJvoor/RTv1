#include "rtv1.h"

//TODO: not a trustable function, segfault if there are not integers
//TODO: Need to rewrite!

char		*get_sign(char *sign, char *str)
{
	*sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r'))
		str++;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	return (str);
}

char		*get_first_num(char *str, float *box)
{
	int		i;

	i = 0;
	if (*str < '0' || *str > '9')
		return (NULL);
	while (str[i] && ((str[i] >= '0' && str[i] <= '9')))
		i++;
	if (str[i] != '.' && str[i] != ',')
		return (NULL);
	str[i] = '\0';
	*box = ft_atoi(str);
	str += i + 1;
	return (str);
}

char		*get_second_num(char *str, float *box)
{
	int		i;
	char	flag;
	float	res;

	i = 0;
	flag = 1;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9')))
		i++;
	if (str[i] == '\0')
		flag = 0;
	else if (str[i] != ',' && str[i] != ' ' && str[i] != '\t')
		return (NULL);
	str[i] = '\0';
	res = ft_atoi(str);
	while (res >= 1)
		res /= 10.0;
	*box += res;
	str += i + flag;
	return (str);
}

char		*parse_float(char *str, float *box)
{
	int		i;
	char	sign;

	i = 0;
	str = get_sign(&sign, str);
	str = get_first_num(str, box);
	if (str == NULL || *str < '0' || *str > '9')
		return (NULL);
	str = get_second_num(str, box);
	if (str == NULL)
		return (NULL);
	*box *= sign;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r'))
		str++;
	return (str);
}
