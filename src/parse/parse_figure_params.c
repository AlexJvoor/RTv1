#include "rtv1.h"

int		parse_plane(t_obj **obj, t_data *data, t_parse *parse)
{
	char			*str;
	t_plane			*plane;
	static char		*message = "Plane data is wrong: \"src/parse/figure.c\"";

	plane = (t_plane *)*obj;
	str = skip_to("", parse->gnl_str);
	if (*str == 'c')
	{
		if (parse_coordinates(str, &plane->norm, data, parse) == -1)
			parse_color(str, &plane->color, data, parse);
	}
	else if (*str == 'd')
		safe_call_int_parse(parse_float_param("distance", &plane->dist, parse),
							message, data, parse);
	else if (*str == 's')
		safe_call_int_parse(parse_float_param("shine", &plane->shine, parse),
							message, data, parse);
	else
		safe_call_int_parse(-1, message, data, parse);
	ft_strdel(&parse->gnl_str);
	return (0);
}

int		parse_sphere(t_obj **obj, t_data *data, t_parse *parse)
{
	t_sphere		*sphere;
	char			*str;
	static char		*message = "sphere data is wrong: \"src/parse/figure.c\"";

	sphere = (t_sphere *)*obj;
	str = skip_to("", parse->gnl_str);
	if (*str == 'c')
	{
		if (parse_coordinates(str, &sphere->coords, data, parse) == -1)
			parse_color(str, &sphere->color, data, parse);
	}
	else if (*str == 'r')
		safe_call_int_parse(parse_float_param("radius", &sphere->rad, parse),
							message, data, parse);
	else if (*str == 's')
		safe_call_int_parse(parse_float_param("shine", &sphere->shine, parse),
							message, data, parse);
	else
		safe_call_int_parse(-1, message, data, parse);
	ft_strdel(&parse->gnl_str);
	return (0);
}

int		parse_cone(t_obj **obj, t_data *data, t_parse *parse)
{
	t_cone			*cone;
	char			*str;
	static char		*message = "cone data is wrong: \"src/parse/figure.c\"";

	cone = (t_cone *)*obj;
	str = skip_to("", parse->gnl_str);
	if (*str == 'c')
	{
		if (parse_coordinates(str, &cone->coords, data, parse) == -1)
			parse_color(str, &cone->color, data, parse);
	}
	else if (*str == 'd')
		parse_vec3("dir_vec", &cone->dir_vec, data, parse);
	else if (*str == 't')
	{
		safe_call_int_parse(parse_float_param("tangent", &cone->tg, parse),
							message, data, parse);
	}
	else if (*str == 's')
		safe_call_int_parse(parse_float_param("shine", &cone->shine, parse),
							message, data, parse);
	else
		safe_call_int_parse(-1, message, data, parse);
	ft_strdel(&parse->gnl_str);
	return (0);
}

int		parse_cylinder(t_obj **obj, t_data *data, t_parse *parse)
{
	t_cylinder		*cylinder;
	char			*str;
	static char		*message = "cylinder data is wrong: \"src/parse/figure.c\"";

	cylinder = (t_cylinder *)*obj;
	str = skip_to("", parse->gnl_str);
	if (*str == 'c')
	{
		if (parse_coordinates(str, &cylinder->coords, data, parse) == -1)
			parse_color(str, &cylinder->color, data, parse);
	}
	else if (*str == 'r')
		safe_call_int_parse(parse_float_param("radius", &cylinder->rad, parse),
		message, data, parse);
	else if (*str == 'd')
		parse_vec3("dir_vec", &cylinder->dir_vec, data, parse);
	else if (*str == 's')
		safe_call_int_parse(parse_float_param("shine", &cylinder->shine, parse),
							message, data, parse);
	else
		safe_call_int_parse(-1, message, data, parse);
	ft_strdel(&parse->gnl_str);
	return (0);
}
