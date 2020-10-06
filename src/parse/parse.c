//
// Created by Hugor Chau on 10/5/20.
//

#include "rtv1.h"

/*
**			checking parsed objects
*/

void			check_data(t_data *data)
{
	t_list		*lst;

	lst = data->objs;
	while (lst)
	{
		if ((*(t_obj **)lst->content)->type == SPHERE)
		{
			printf("Type: sphere\ncoordinates: %f, %f, %f\nradius: %f\n\n",
				   (*(t_sphere **)lst->content)->coords.x, (*(t_sphere **)lst->content)->coords.y,
				   (*(t_sphere **)lst->content)->coords.z, (*(t_sphere **)lst->content)->rad);
		}
		if ((*(t_obj **)lst->content)->type == PLANE)
		{
			printf("Type: plane\ncoordinates: %f, %f, %f\ndistance: %f\n\n",
				   (*(t_plane **)lst->content)->coords.x, (*(t_plane **)lst->content)->coords.y,
				   (*(t_plane **)lst->content)->coords.z, (*(t_plane **)lst->content)->dist);
		}
		if ((*(t_obj **)lst->content)->type == CONE)
		{
			printf("Type: cone\ncoordinates: %f, %f, %f\ndir_vec: %f, %f, %f\n"
				   "tangent: %f\n\n",
				   (*(t_cone **)lst->content)->coords.x, (*(t_cone **)lst->content)->coords.y,
				   (*(t_cone **)lst->content)->coords.z,
				   (*(t_cone **)lst->content)->dir_vec.x, (*(t_cone **)lst->content)->dir_vec.y,
				   (*(t_cone **)lst->content)->dir_vec.z,
				   (*(t_cone **)lst->content)->tg);
		}
		if ((*(t_obj **)lst->content)->type == CYLINDER)
		{
			printf("Type: cylinder\ncoordinates: %f, %f, %f\ndir_vec: %f, %f, %f\n",
				   (*(t_cylinder **)lst->content)->coords.x, (*(t_cylinder **)lst->content)->coords.y,
				   (*(t_cylinder **)lst->content)->coords.z,
				   (*(t_cone **)lst->content)->dir_vec.x, (*(t_cone **)lst->content)->dir_vec.y,
				   (*(t_cone **)lst->content)->dir_vec.z);
		}
		lst = lst->next;
	}
}

/*
**		works with *.txt for now
*/

int				open_file(char *map_name, t_data *data)
{
	int fd = open(map_name, O_RDONLY);
	if (fd < 3)
		safe_call_int(-1, "Can't open file, try again.", data);
	return (fd);
}

static void		end_parse(t_data *data, t_parse *parse)
{
	t_list	*tmp;

	safe_call_int_parse(parse->gnl_flag, "Read error: gnl returned -1.", data, parse);
	remove_parse(parse);
	tmp = data->objs;
	data->objs = data->objs->next;
	ft_memdel((void **)&tmp);
}

static void		parse_file(int fd, t_data *data)
{
	t_parse		parse;

	parse.fd = fd;
	data->objs = ft_lstnew(NULL, 0);
	parse.curr_obj = data->objs;
	data->light = ft_memalloc(sizeof(t_light));
	parse.light = data->light;
	while ((parse.gnl_flag = get_next_line(fd, &parse.gnl_str)) == 1)
	{
		if (!*parse.gnl_str)
			;
		else if (*parse.gnl_str == 'l')
			parse_light(data, &parse);
		else if (*parse.gnl_str == 'p')
			parse_plane(data, &parse);
		else if (*parse.gnl_str == 's')
		{
			parse_sphere(data, &parse);
		}
		else if (*parse.gnl_str == 'c')
		{
			if (parse_cone(data, &parse) == -1)
				parse_cylinder(data, &parse);
		}
		else
			safe_call_int_parse(-1, "LOL", data, &parse);
		ft_strdel(&parse.gnl_str);
	}
	end_parse(data, &parse);
}

void	parse(char *str, t_data *data)
{
	parse_file(open_file(str, data), data);
	check_data(data);
}
