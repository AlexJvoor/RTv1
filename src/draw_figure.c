//
// Created by Hugor Chau on 10/6/20.
//

#include "rtv1.h"

t_vec3		eye_trace(int x, int y, t_cam *cam)
{
	return (vec3_normalize(vec3_minus((t_vec3){(x) * (VX),
				(y) * (VY), 1.0}, cam->pos)));
}

int			vec3_to_color(t_vec3 vec)
{
	t_vec3		res_vec;
	int			color;

	res_vec = vec3_mult_num(vec, 255);
	res_vec.x = res_vec.x > 255 ? 255 : res_vec.x;
	res_vec.y = res_vec.y > 255 ? 255 : res_vec.y;
	res_vec.z = res_vec.z > 255 ? 255 : res_vec.z;
	res_vec.x = res_vec.x < 0 ? 0 : res_vec.x;
	res_vec.y = res_vec.y < 0 ? 0 : res_vec.y;
	res_vec.z = res_vec.z < 0 ? 0 : res_vec.z;
	color = 0 << 24 | (int)res_vec.x << 16 | (int)res_vec.y << 8 | (int)res_vec.z;
	return (color);
}

float		light_cast(t_data *data, t_obj *obj, float min_dist, t_vec3 d)
{
	t_vec3		l;
	t_vec3		p;
	t_vec3		normal;

	p = vec3_plus(vec3_mult_num(d, min_dist), data->cam.pos);
	l = vec3_minus(p, data->light->coord);
	normal = data->find_normal[obj->type](obj, &d, p);
	return (vec3_dot(vec3_normalize(l), normal) / (vec3_len(normal) * vec3_len(l)));
}

int			final_color(t_data *data, t_obj *obj, float min_dist, t_vec3 d)
{
	float		light_intence;
	int			color_res;

	light_intence = light_cast(data, obj, min_dist, d);
	color_res = vec3_to_color(vec3_mult_num(obj->color, light_intence));
	return (color_res);
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

