//
// Created by Hugor Chau on 10/5/20.
//
#include "rtv1.h"
#define ERROR			"\033[38;2;200;0;30m"
#define EOC				"\033[38;2;0m"

void	remove_parse(t_parse *parse)
{
	ft_strdel(&parse->gnl_str);
}

int		safe_call_int_parse(int res, char *message, t_data *data, t_parse *parse)
{
	if (res == 0)
		return (res);
	remove_parse(parse);
	safe_call_int(-1, message, data);
}

void	*safe_call_ptr_parse(void *res, char *message, t_data *data, t_parse *parse)
{
	if (res != NULL)
		return (res);
	remove_parse(parse);
	safe_call_int(-1, message, data);
}
