#include "rtv1.h"

/*
**		works with *.txt for now
*/

int				open_file(char *map_name, t_data *data)
{
	int fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 3)
		safe_call_int(-1, "Can't open file, try again.", data);
	return (fd);
}

static void		end_parse(t_data *data, t_parse *parse)
{
	t_list	*tmp;

	safe_call_int_parse(parse->gnl_flag,
			"Read error: gnl returned -1.", data, parse);
//	remove_parse(parse);
	tmp = data->objs;
	data->objs = data->objs->next;
	ft_memdel((void **)&tmp);
}

static void		parse_single_object(t_data *data, t_parse *parse)
{
	if (*parse->gnl_str == 'l')
		parse_light(data, parse);
	else if (*parse->gnl_str == 'p')
		parse_figure(PLANE, data, parse);
	else if (*parse->gnl_str == 's')
		parse_figure(SPHERE, data, parse);
	else if (*parse->gnl_str == 'c')
	{
		if ((check_line("cone", parse->gnl_str)) == 0)
			parse_figure(CONE, data, parse);
		else if ((check_line("cylinder", parse->gnl_str)) == 0)
			parse_figure(CYLINDER, data, parse);
		else if ((check_line("camera", parse->gnl_str)) == 0)
			parse_camera(data, parse);
		else
			safe_call_int_parse(-1, "Object name is incorrect.", data, parse);
	}
	else
		safe_call_int_parse(-1, "Object name is incorrect.", data, parse);
}

static void		parse_file(int fd, t_data *data)
{
	t_parse		parse;

	parse.fd = fd;
	data->objs = ft_lstnew(NULL, 0);
	parse.curr_obj = data->objs;
	while ((parse.gnl_flag = get_next_line(fd, &parse.gnl_str)) == 1)
	{
		if (*parse.gnl_str)
			parse_single_object(data, &parse);
		ft_strdel(&parse.gnl_str);
	}
	end_parse(data, &parse);
}

void			parse(char *str, t_data *data)
{
	parse_file(open_file(str, data), data);
	check_data(data);
}
