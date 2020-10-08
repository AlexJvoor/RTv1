#include "rtv1.h"

/*
**		It's pretty fun and usable;
**		tell me please if it's difficult to read
*/

static size_t	get_obj_size(int obj_type)
{
	static size_t	obj_size[OBJ_COUNT] = {sizeof(t_sphere),
					sizeof(t_plane), sizeof(t_cone), sizeof(t_cylinder)};

	return (obj_size[obj_type]);
}

static void		get_an_object(t_obj **obj, int obj_type,
								t_data *data, t_parse *parse)
{
	static char		*start_flag[OBJ_COUNT] = {"sphere",
						"plane", "cone", "cylinder"};

	safe_call_int_parse(check_line(start_flag[obj_type], parse->gnl_str),
				"Figure data is wrong: \"src/parse/figure.c\"", data, parse);
	*obj = safe_call_ptr_parse(ft_memalloc(get_obj_size(obj_type)),
				"Malloc crashed: \"src/parse/figure.c\"", data, parse);
	(*obj)->type = obj_type;
}

static char		*get_end_line(int obj_type)
{
	static char		*end_flag[OBJ_COUNT] = {"t_sphere",
					"t_plane", "t_cone", "t_cylinder"};

	return (end_flag[obj_type]);
}

static void		*get_parse_function(int obj_type)
{
	static int		(*parse_object[OBJ_COUNT])(t_obj **obj,
					t_data *, t_parse *) = {&parse_sphere,
					&parse_plane, &parse_cone, &parse_cylinder};

	return (parse_object[obj_type]);
}

void			parse_figure(int obj_type, t_data *data, t_parse *parse)
{
	t_obj			*obj;
	char			*end_flag;
	int				(*parse_line)(t_obj **obj, t_data *, t_parse *);

	if (obj_type >= OBJ_COUNT || obj_type < 0)
		safe_call_int_parse(-1,
			"Incorrect type num: \"./src/parse/parse_figure.c\"", data, parse);
	parse_line = get_parse_function(obj_type);
	end_flag = get_end_line(obj_type);
	get_an_object(&obj, obj_type, data, parse);
	ft_strdel(&parse->gnl_str);
	while ((parse->gnl_flag = get_next_line(parse->fd, &parse->gnl_str)) == 1
			&& check_line(end_flag, parse->gnl_str))
	{
		parse_line(&obj, data, parse);
	}
	parse->curr_obj->next = ft_lstnew((&obj), sizeof(t_obj *));
	parse->curr_obj = parse->curr_obj->next;
}
