//
// Created by Hugor Chau on 10/6/20.
//

#include "rtv1.h"

t_vec3		eye_trace(int x, int y, t_cam *cam)
{
	return (vec3_normalize(vec3_minus((t_vec3){(x) * (VX),
				(y) * (VY), 1.0}, cam->pos)));
}

void		draw_figure(int x, int y, t_data *data)
{
	t_list		*tmp;
	t_vec3		d;
	float		res;

	data->cam.pos.x = 0;
	data->cam.pos.y = 0;
	data->cam.pos.z = 0;

	d = eye_trace(x, y, &data->cam);
	tmp = data->objs;
	while (tmp)
	{
		res = data->find_destination[(*(t_obj **)tmp->content)->type](data, *(t_obj **)tmp->content, &d);
		if (res > 1 && res < INFINITY)
		{
			data->mlx.data[x + WIDTH / 2 + (y + HEIGHT / 2) * WIDTH] = 0x00FF00FF;
		}
		tmp = tmp->next;
	}
}

