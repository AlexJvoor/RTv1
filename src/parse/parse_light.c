#include "rtv1.h"

static void		parse_light_str(t_light *light, t_data *data, t_parse *parse)
{
	char			*str;
	static char		*message = "light data is wrong: \"src/parse/figure.c\"";

	str = skip_to("", parse->gnl_str);
	if (*str == 'c')
	{
		if (parse_coordinates(str, &light->coord, data, parse) == -1)
			parse_color(str, &light->color, data, parse);
	}
	else if (*str == 'l')
		safe_call_int_parse(parse_t_num_param("light_pov",
							&light->light_pov, parse),
							message, data, parse);
	else
		safe_call_int_parse(-1, message, data, parse);
}

static void		init_light(t_light **light, t_data *data, t_parse *parse)
{
	*light = safe_call_ptr_parse(ft_memalloc(sizeof(t_light)),
			"Malloc crashed: \"./src/parse/parse_light.c\"", data, parse);
	safe_call_int_parse(check_line("light", parse->gnl_str),
			"light data is wrong: \"src/parse/parse_light.c\"", data, parse);
	ft_strdel(&parse->gnl_str);
	(*light)->type = LIGHT;
}

int				parse_light(t_data *data, t_parse *parse)
{
	t_light		*light;

	init_light(&light, data, parse);
	while ((parse->gnl_flag = get_next_line(parse->fd, &parse->gnl_str)) == 1
			&& check_line("t_light", parse->gnl_str))
	{
		parse_light_str(light, data, parse);
		ft_strdel(&parse->gnl_str);
	}
	if (data->light == NULL)
	{
		data->light = light;
		parse->light = light;
	}
	else
	{
		parse->light->next = light;
		parse->light = parse->light->next;
	}
	return (0);
}
