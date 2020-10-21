#include "rtv1.h"

char		*skip_to(char *check, char *original)
{
	while (*original &&
		(*original == ' ' || *original == '\t' || *original == '\r'))
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
	while (*original &&
		(*original == ' ' || *original == '\t' || *original == '\r'))
		original++;
	return (original);
}

/*
**		this function checks if word or line were correct
*/

int			check_line(char *should_be, char *check)
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

void		parse_vec3(char *flag_str,
					t_vec3 *coordinates, t_data *data, t_parse *parse)
{
	char		*str;
	static char	*message = "t_vec3 is wrong, \"src/parse/tools.c\"";

	str = safe_call_ptr_parse(skip_to(flag_str, parse->gnl_str),
		message, data, parse);
	str = safe_call_ptr_parse(skip_to("x", str),
		message, data, parse);
	str = safe_call_ptr_parse(parse_t_num(str, &coordinates->x),
		message, data, parse);
	str = safe_call_ptr_parse(skip_to("y", str),
		message, data, parse);
	str = safe_call_ptr_parse(parse_t_num(str, &coordinates->y),
		message, data, parse);
	str = safe_call_ptr_parse(skip_to("z", str),
		message, data, parse);
	str = safe_call_ptr_parse(parse_t_num(str, &coordinates->z),
		message, data, parse);
}
