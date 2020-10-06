//
// Created by Hugor Chau on 10/6/20.
//

#include "rtv1.h"

t_vec3		eye_trace(int x, int y, t_cam *cam)
{
	return (vec3_normalize(vec3_minus((t_vec3){(x) * (VX),
				(y) * (VY), 1.0}, cam->pos)));
}

//TODO: incorrect num!
int			vec3_to_color(t_vec3 vec)
{
	t_vec3		res_vec;
	int			color;

	res_vec = vec3_mult_num(vec, 255);
	color = 0 << 24 | (int)res_vec.x << 16 | (int)res_vec.y << 8 | (int)res_vec.z;
	return (color);
}

void		draw_figure(int x, int y, t_data *data)
{
	t_list		*tmp;
	t_vec3		d;
	float		dist;
	float		min_dist;
	t_obj		*obj;

	data->cam.pos.x = 0;
	data->cam.pos.y = 0;
	data->cam.pos.z = 0;

	min_dist = INFINITY;
	d = eye_trace(x, y, &data->cam);//o + t * vec(d)
	tmp = data->objs;
	while (tmp)
	{
		dist = data->find_destination[(*(t_obj **)tmp->content)->type](data, *(t_obj **)tmp->content, &d);
		if (dist > 1 && dist < INFINITY)
		{
			if (dist < min_dist)
			{
				min_dist = dist;
				obj = *(t_obj **)tmp->content;
			}
		}
		tmp = tmp->next;
	}
	if (min_dist != INFINITY)
	{
		data->mlx.data[x + H_WIDTH + (y + H_HEIGHT) * WIDTH] = vec3_to_color(obj->color);
	}
}

