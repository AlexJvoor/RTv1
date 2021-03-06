/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:38:38 by hchau             #+#    #+#             */
/*   Updated: 2020/10/21 15:38:40 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**		It's pretty fun and usable;
**		tell me please if it's difficult to read
*/

static void		get_an_object(t_obj **obj, int obj_type,
								t_data *data, t_parse *parse)
{
	static char		*start_flag[OBJ_COUNT] = {"sphere",
						"plane", "cone", "cylinder"};
	static size_t	obj_size[OBJ_COUNT] = {sizeof(t_sphere),
						sizeof(t_plane), sizeof(t_cone), sizeof(t_cylinder)};

	safe_call_int_parse(check_line(start_flag[obj_type], parse->gnl_str),
				"Figure data is wrong: \"src/parse/figure.c\"", data, parse);
	*obj = safe_call_ptr_parse(ft_memalloc(obj_size[obj_type]),
				"Malloc crashed: \"src/parse/figure.c\"", data, parse);
	(*obj)->type = obj_type;
}

static char		*get_end_line(int obj_type)
{
	static char		*end_flag[OBJ_COUNT] = {"t_sphere",
					"t_plane", "t_cone", "t_cylinder"};

	return (end_flag[obj_type]);
}

static void		*get_normal_function(int obj_type)
{
	static t_vec3	(*normal_function[OBJ_COUNT])(t_obj *obj,
					t_vec3 *d, t_num min_dist, t_cam cam) = {&sphere_normal,
					&plane_normal, &cone_normal, &cylinder_normal};

	return (normal_function[obj_type]);
}

void			check_plane(t_plane *plane)
{
	if (plane->type != PLANE)
		return ;
	if (plane->norm.x * plane->coords.x < 0)
	{
		plane->norm.x *= plane->norm.x < 0 ? 1 : -1;
		plane->coords.x *= plane->coords.x < 0 ? 1 : -1;
	}
	if (plane->norm.y * plane->coords.y < 0)
	{
		plane->norm.y *= plane->norm.y < 0 ? 1 : -1;
		plane->coords.y *= plane->coords.y < 0 ? 1 : -1;
	}
	if (plane->norm.z * plane->coords.z < 0)
	{
		plane->norm.z *= plane->norm.z < 0 ? 1 : -1;
		plane->coords.z *= plane->coords.z < 0 ? 1 : -1;
	}
}

void			parse_figure(int obj_type, t_data *data, t_parse *parse)
{
	t_obj			*obj;
	char			*end_flag;
	static int		(*parse_object[OBJ_COUNT])(t_obj **obj,
						t_data *, t_parse *) = {&parse_sphere,
						&parse_plane, &parse_cone, &parse_cylinder};

	if (obj_type >= OBJ_COUNT || obj_type < 0)
		safe_call_int_parse(-1,
			"Incorrect type num: \"./src/parse/parse_figure.c\"", data, parse);
	end_flag = get_end_line(obj_type);
	get_an_object(&obj, obj_type, data, parse);
	ft_strdel(&parse->gnl_str);
	while ((parse->gnl_flag = get_next_line(parse->fd, &parse->gnl_str)) == 1
			&& check_line(end_flag, parse->gnl_str))
	{
		parse_object[obj_type](&obj, data, parse);
	}
	obj->find_normal = get_normal_function(obj_type);
	obj->bright_cast = &bright_cast;
	parse->curr_obj->next = ft_lstnew((&obj), sizeof(t_obj *));
	parse->curr_obj = parse->curr_obj->next;
	check_plane((t_plane *)obj);
}
