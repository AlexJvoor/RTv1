#include "rtv1.h"

int		parse_t_num_param(char *check, t_num *box, t_parse *parse)
{
	char			*str;

	str = skip_to(check, parse->gnl_str);
	if (str == NULL)
		return (-1);
	str = parse_t_num(str, box);
	if (str == NULL)
		return (-1);
	return (0);
}

int		parse_coordinates(char *str, t_vec3 *coordinates,
								t_data *data, t_parse *parse)
{
	if ((check_line("coordinates", str)))
		return (-1);
	parse_vec3("coordinates", coordinates, data, parse);
	return (0);
}

int		parse_color(char *str, t_vec3 *color, t_data *data, t_parse *parse)
{
	if ((check_line("color", str)))
	{
		safe_call_int_parse(-1, "Color parse error.", data, parse);
		return (-1);
	}
	parse_vec3("color", color, data, parse);
	if (color->x < 0 || color->x > 1 ||
		color->y < 0 || color->y > 1 ||
		color->z < 0 || color->z > 1)
		safe_call_int_parse(-1, "Color parse error.", data, parse);
	return (0);
}
