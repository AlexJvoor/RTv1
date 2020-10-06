//
// Created by Hugor Chau on 10/5/20.
//

#include "rtv1.h"

char		*skip_to(char *check, char *original)
{
	while (*original && (*original == ' ' || *original == '\t' || *original == '\r'))
		original++;
	while (*check && *original)
	{
		if (*original != *check)
			return (NULL);
		check++;
		original++;
	}
	if (*check)
		return (NULL);
	while (*original && (*original == ' ' || *original == '\t' || *original == '\r'))
		original++;
	return (original);
}

//TODO: not a trustable function, segfault if there are not integers

char		*parse_float(char *str, float *box)
{
	float	res;
	int		i;
	char	flag;
	char	sign;

	i = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (NULL);
	while (str[i] && ((str[i] >= '0' && str[i] <= '9')))
		i++;
	if (str[i] != '.' && str[i] != ',')
		return (NULL);
	str[i] = '\0';
	*box = ft_atoi(str);
	str += i + 1;
	if (*str < '0' || *str > '9')
		return (NULL);
	i = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9')))
		i++;
	flag = str[i] == '\0' ? 0 : 1;
	str[i] = '\0';
	res = ft_atoi(str);
	while (res > 1)
		res /= 10.0;
	*box += res;
	str += i + flag;
	*box *= sign;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r'))
		str++;
	return (str);
}

/*
**		this function checks if word or line were correct
*/

int				check_line(char *should_be, char *check)
{
	if (!check || !should_be || !*check)
		return (1);
	while (*check && (*check == ' ' || *check == '\t' || *check == '\r'))
		check++;
	if (!*check)
		return (1);
	while (*should_be && *check && *should_be == *check)
	{
		check++;
		should_be++;
	}
	while (*check && (*check == ' ' || *check == '\t' || *check == '\r'))
		check++;
	return (*should_be == '\0' ? 0 : 1);
}

/*
**		local check at when one object was parsed
*/

void		check_error(char gnl_read_flag, char brackets, t_data *data)
{
	if (gnl_read_flag == -1)
		safe_call_int(-1, "Read error: gnl returned -1.", data);
	safe_call_int(brackets, "Parse error: "
								  "check for brackets.", data);
}

void		parse_vec3(char *str, t_vec3 *coordinates, t_data *data, t_parse *parse)
{
	str = safe_call_ptr_parse(skip_to("x", str),
		"Parser failed: coordinates are wrong - \"src/parse/tools.c11\"", data, parse);
	str = safe_call_ptr_parse(parse_float(str, &coordinates->x),
		"Parser failed: coordinates are wrong - \"src/parse/tools.c22\"", data, parse);
	str = safe_call_ptr_parse(skip_to("y", str),
		"Parser failed: coordinates are wrong - \"src/parse/tools.c33\"", data, parse);
	str = safe_call_ptr_parse(parse_float(str, &coordinates->y),
		"Parser failed: coordinates are wrong - \"src/parse/tools.c44\"", data, parse);
	str = safe_call_ptr_parse(skip_to("z", str),
		"Parser failed: coordinates are wrong - \"src/parse/tools.c55\"", data, parse);
	str = safe_call_ptr_parse(parse_float(str, &coordinates->z),
		"Parser failed: coordinates are wrong - \"src/parse/tools.c66\"", data, parse);
}