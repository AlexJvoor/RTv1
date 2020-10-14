//
// Created by Hugor Chau on 10/6/20.
//

#include "rtv1.h"

t_vec3		eye_trace(int x, int y, t_cam *cam)
{
	return (vec3_normalize(vec3_minus((t_vec3){(x) * (VX),
				(y) * (VY), 1.0}, cam->pos)));
}

int			final_color(t_data *data, t_obj *obj, float min_dist, t_vec3 d)
{
	t_light		*tmp;
	t_vec3		color;
	t_vec3		p;

	tmp = data->light;
	color.x = 0;
	color.y = 0;
	color.z = 0;
	while (tmp)
	{
		color = vec3_plus(curr_color(obj, d, tmp, min_dist, data), color);
		tmp = tmp->next;
	}
	return (vec3_to_color(color));
}

void		draw_figure(int x, int y, t_data *data)
{
	t_list		*tmp;
	t_vec3		d;
	float		dist;
	float		min_dist;
	t_obj		*obj;

	/**
	**		camera is parsed, sooo we don't need this
	**		hardcoded coordinates anymore
	*/

	min_dist = INFINITY;
	d = eye_trace(x, y, &data->cam);//o + t * vec(d)
	tmp = data->objs;
	while (tmp)
	{
//	    func = data->find_destination[(*(t_obj **)tmp->content)->type];
//	    dist = func(data, *(t_obj **)tmp->content, &d);
		dist = data->find_destination[(*(t_obj **)tmp->content)->type](data, *(t_obj **)tmp->content, &d, &data->cam.pos);
		if (dist > 0 && dist < INFINITY)
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
		data->mlx.data[x + H_WIDTH + (y + H_HEIGHT) * WIDTH] = final_color(data, obj, min_dist, d);
	}
	if (min_dist != INFINITY)
	{
//		data->mlx.data[x + H_WIDTH + (y + H_HEIGHT) * WIDTH] = 0x0000ffff;
//		float g = sqrt(1 / (min_dist + 1));//extra / for "debaga"
//		data->mlx.data[x + H_WIDTH + (y + H_HEIGHT) * WIDTH] = vec3_to_color((t_vec3){g, g, g});
	}
	else
	{
		data->mlx.data[x + H_WIDTH + (y + H_HEIGHT) * WIDTH] = 0; // black
	}
}

