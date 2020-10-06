//
// Created by Hugor Chau on 10/5/20.
//

#include "rtv1.h"

int		parse_light(t_data *data, t_parse *parse)
{
	t_light	*light;
	char	*str;

	light = ft_memalloc(sizeof(t_light));
	safe_call_int_parse(check_line("light", parse->gnl_str),
						"light data is wrong: \"src/parse/figure.c\"", data, parse);
	ft_strdel(&parse->gnl_str);
	while ((parse->gnl_flag = get_next_line(parse->fd, &parse->gnl_str)) == 1
		   && check_line("t_light", parse->gnl_str))
	{
		str = skip_to("", parse->gnl_str);
		if (*str == 'c')
		{
			str = safe_call_ptr_parse(skip_to("coordinates", str),
								"Parser failed: coordinates are wrong - \"src/parse/tools.c\"", data, parse);
			parse_vec3(str, &light->coord, data, parse);
		}
		else if (*str == 'l')
		{
			str = safe_call_ptr_parse(skip_to("light_pov", str),
								"light data is wrong: \"src/parse/figure.c\"", data, parse);
			str = safe_call_ptr_parse(parse_float(str, &light->light_pov),
								"light data is wrong: \"src/parse/figure.c\"", data, parse);
		}
		else
			safe_call_int_parse(-1,
								"light data is wrong: \"src/parse/figure.c\"", data, parse);
		ft_strdel(&parse->gnl_str);
	}
	light->type = LIGHT;
	data->light = light;
//	parse->light = parse->light->next;
	return (0);
}

int		parse_plane(t_data *data, t_parse *parse)
{
	t_plane	*plane;
	char	*str;

	plane = ft_memalloc(sizeof(t_plane));
	safe_call_int_parse(check_line("plane", parse->gnl_str),
		"Plane data is wrong: \"src/parse/figure.c\"", data, parse);
	ft_strdel(&parse->gnl_str);
	while ((parse->gnl_flag = get_next_line(parse->fd, &parse->gnl_str)) == 1
			&& check_line("t_plane", parse->gnl_str))
	{
		str = skip_to("", parse->gnl_str);
		if (*str == 'c')
		{
			str = safe_call_ptr_parse(skip_to("coordinates", str),
				"Parser failed: coordinates are wrong - \"src/parse/tools.c\"", data, parse);
			parse_vec3(str, &plane->coords, data, parse);
		}
		else if (*str == 'd')
		{
			str = safe_call_ptr_parse(skip_to("distance", str),
			"Plane data is wrong: \"src/parse/figure.c\"", data, parse);
			str = safe_call_ptr_parse(parse_float(str, &plane->dist),
				"Plane data is wrong: \"src/parse/figure.c\"", data, parse);
		}
		else
			safe_call_int_parse(-1,
			"Plane data is wrong: \"src/parse/figure.c\"", data, parse);
		ft_strdel(&parse->gnl_str);
	}
	plane->type = PLANE;
	parse->curr_obj->next = ft_lstnew((&plane), sizeof(t_plane *));
	parse->curr_obj = parse->curr_obj->next;
	return (0);
}

int		parse_sphere(t_data *data, t_parse *parse)
{
	t_sphere	*sphere;
	char	*str;

	safe_call_int_parse(check_line("sphere", parse->gnl_str),
						"sphere data is wrong: \"src/parse/figure.c\"", data, parse);
	sphere = ft_memalloc(sizeof(t_sphere));
	ft_strdel(&parse->gnl_str);
	while ((parse->gnl_flag = get_next_line(parse->fd, &parse->gnl_str)) == 1
		   && check_line("t_sphere", parse->gnl_str))
	{
		str = skip_to("", parse->gnl_str);
		if (*str == 'c')
		{
			str = safe_call_ptr_parse(skip_to("coordinates", str),
				"Parser failed: coordinates are wrong - \"src/parse/tools.c\"", data, parse);
			parse_vec3(str, &sphere->coords, data, parse);
		}
		else if (*str == 'r')
		{
			str = safe_call_ptr_parse(skip_to("radius", str),
								"sphere data is wrong: \"src/parse/figure.c\"", data, parse);
			str = safe_call_ptr_parse(parse_float(str, &sphere->rad),
								"sphere data is wrong: \"src/parse/figure.c\"", data, parse);
		}
		else
			safe_call_int_parse(-1,
								"sphere data is wrong: \"src/parse/figure.c\"", data, parse);
		ft_strdel(&parse->gnl_str);
	}
	sphere->type = SPHERE;
	printf("radius: %f\n",
		   sphere->rad);
	parse->curr_obj->next = ft_lstnew((&sphere), sizeof(t_sphere *));
	parse->curr_obj = parse->curr_obj->next;
	return (0);
}

int 		parse_cone(t_data *data, t_parse *parse)
{
	t_cone	*cone;
	char	*str;

	cone = ft_memalloc(sizeof(t_cone));
	if (check_line("cone", parse->gnl_str))
		return (-1);
	ft_strdel(&parse->gnl_str);
	while ((parse->gnl_flag = get_next_line(parse->fd, &parse->gnl_str)) == 1
		   && check_line("t_cone", parse->gnl_str))
	{
		str = skip_to("", parse->gnl_str);
		if (*str == 'c')
		{
			str = safe_call_ptr_parse(skip_to("coordinates", str),
								"Parser failed: coordinates are wrong - \"src/parse/tools.c\"", data, parse);
			parse_vec3(str, &cone->coords, data, parse);
		}
		else if (*str == 'd')
		{
			str = safe_call_ptr_parse(skip_to("dir_vec", str),
								"Parser failed: coordinates are wrong - \"src/parse/tools.c\"", data, parse);
			parse_vec3(str, &cone->dir_vec, data, parse);
		}
		else if (*str == 't')
		{
			str = safe_call_ptr_parse(skip_to("tangent", str),
								"cone data is wrong: \"src/parse/figure.c\"", data, parse);
			str = safe_call_ptr_parse(parse_float(str, &cone->tg),
								"cone data is wrong: \"src/parse/figure.c\"", data, parse);
		}
		else
			safe_call_int_parse(-1,
								"cone data is wrong: \"src/parse/figure.c\"", data, parse);
		ft_strdel(&parse->gnl_str);
	}
	cone->type = CONE;
	parse->curr_obj->next = ft_lstnew((&cone), sizeof(t_cone *));
	parse->curr_obj = parse->curr_obj->next;
	return (0);
}

int		parse_cylinder(t_data *data, t_parse *parse)
{
	t_cylinder	*cylinder;
	char		*str;

	cylinder = ft_memalloc(sizeof(t_cylinder));
	safe_call_int_parse(check_line("cylinder", parse->gnl_str),
						"cylinder data is wrong: \"src/parse/figure.c\"", data, parse);
	ft_strdel(&parse->gnl_str);
	while ((parse->gnl_flag = get_next_line(parse->fd, &parse->gnl_str)) == 1
		   && check_line("t_cylinder", parse->gnl_str))
	{
		str = skip_to("", parse->gnl_str);
		if (*str == 'c')
		{
			str = safe_call_ptr_parse(skip_to("coordinates", str),
								"Parser failed: coordinates are wrong - \"src/parse/tools.c\"", data, parse);
			parse_vec3(str, &cylinder->coords, data, parse);
		}
		else if (*str == 'd')
		{
			str = safe_call_ptr_parse(skip_to("dir_vec", str),
								"Parser failed: coordinates are wrong - \"src/parse/tools.c\"", data, parse);
			parse_vec3(str, &cylinder->dir_vec, data, parse);
		}
		else
			safe_call_int_parse(-1,
								"cylinder data is wrong: \"src/parse/figure.c\"", data, parse);
		ft_strdel(&parse->gnl_str);
	}
	cylinder->type = CYLINDER;
	parse->curr_obj->next = ft_lstnew((&cylinder), sizeof(t_cylinder *));
	parse->curr_obj = parse->curr_obj->next;
	return (0);
}