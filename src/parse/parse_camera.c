/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:38:27 by hchau             #+#    #+#             */
/*   Updated: 2020/10/21 15:38:29 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		init_cam(t_data *data, t_parse *parse)
{
	safe_call_int_parse(check_line("camera", parse->gnl_str),
		"camera data is wrong: \"src/parse/parse_camera.c\"", data, parse);
	ft_strdel(&parse->gnl_str);
}

static void		parse_line(t_data *data, t_parse *parse)
{
	char			*str;
	static char		*message = "Cam data is wrong: \"src/parse/figure.c\"";

	str = skip_to("", parse->gnl_str);
	if (*str == 'p')
	{
		parse_vec3("position", &data->cam.pos, data, parse);
	}
	else if (*str == 'd')
	{
		if (check_line("direction", parse->gnl_str) == 0)
			parse_vec3("direction", &data->cam.dir, data, parse);
		else if (check_line("deg", parse->gnl_str) == 0)
			parse_vec3("deg", &data->cam.deg, data, parse);
		else
			safe_call_int_parse(-1, message, data, parse);
	}
	else
		safe_call_int_parse(-1, message, data, parse);
}

int				parse_camera(t_data *data, t_parse *parse)
{
	init_cam(data, parse);
	while ((parse->gnl_flag = get_next_line(parse->fd, &parse->gnl_str)) == 1 &&
			check_line("t_camera", parse->gnl_str))
	{
		parse_line(data, parse);
		ft_strdel(&parse->gnl_str);
	}
	return (0);
}
