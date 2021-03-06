/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figure_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:36:56 by hchau             #+#    #+#             */
/*   Updated: 2020/10/21 15:37:00 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_coordinates_or_color(t_obj **obj, t_data *data, t_parse *parse)
{
	char			*str;
	t_plane			*plane;

	plane = (t_plane *)*obj;
	str = skip_to("", parse->gnl_str);
	if (parse_coordinates(str, &plane->coords, data, parse) == -1)
		parse_color(str, &plane->color, data, parse);
}

int		parse_plane(t_obj **obj, t_data *data, t_parse *parse)
{
	char			*str;
	t_plane			*plane;
	static char		*message = "Plane data is wrong: \"src/parse/figure.c\"";

	plane = (t_plane *)*obj;
	str = skip_to("", parse->gnl_str);
	if (*str == 'c')
		parse_coordinates_or_color(obj, data, parse);
	else if (*str == 'n')
	{
		parse_vec3("normal", &plane->norm, data, parse);
		plane->norm = vec3_normalize(plane->norm);
	}
	else if (*str == 'd')
		safe_call_int_parse(parse_t_num_param("distance", &plane->dist, parse),
							message, data, parse);
	else if (*str == 's')
		safe_call_int_parse(parse_t_num_param("shine", &plane->shine, parse),
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
		parse_coordinates_or_color(obj, data, parse);
	else if (*str == 'r')
		safe_call_int_parse(parse_t_num_param("radius", &sphere->rad, parse),
							message, data, parse);
	else if (*str == 's')
		safe_call_int_parse(parse_t_num_param("shine", &sphere->shine, parse),
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
		parse_coordinates_or_color(obj, data, parse);
	else if (*str == 'd')
	{
		parse_vec3("dir_vec", &cone->dir_vec, data, parse);
		cone->dir_vec = vec3_normalize(cone->dir_vec);
	}
	else if (*str == 't')
	{
		safe_call_int_parse(parse_t_num_param("tangent", &cone->tg, parse),
							message, data, parse);
	}
	else if (*str == 's')
		safe_call_int_parse(parse_t_num_param("shine", &cone->shine, parse),
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
		parse_coordinates_or_color(obj, data, parse);
	else if (*str == 'r')
		safe_call_int_parse(parse_t_num_param("radius", &cylinder->rad, parse),
		message, data, parse);
	else if (*str == 'd')
	{
		parse_vec3("dir_vec", &cylinder->dir_vec, data, parse);
		cylinder->dir_vec = vec3_normalize(cylinder->dir_vec);
	}
	else if (*str == 's')
		safe_call_int_parse(parse_t_num_param("shine", &cylinder->shine, parse),
							message, data, parse);
	else
		safe_call_int_parse(-1, message, data, parse);
	ft_strdel(&parse->gnl_str);
	return (0);
}
