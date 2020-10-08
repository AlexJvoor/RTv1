//
// Created by Hugor Chau on 10/6/20.
//

#include "rtv1.h"

t_vec3		eye_trace(int x, int y, t_cam *cam)
{
	return (vec3_normalize(vec3_minus((t_vec3){(x) * (VX),
				(y) * (VY), 1.0}, cam->pos)));
}

//TODO: incorrect num!... or correct?
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

void		draw_figure(int x, int y, t_data *data)
{
	t_list		*tmp;
	t_vec3		d;
	float		dist;
	float		min_dist;
	t_obj		*obj;
	t_vec3		l;
	t_vec3		p;
	t_vec3		normal;

	/**
	**		camera is parsed, sooo we don't need this
	**		hardcoded coordinates anymore
	*/
//	data->cam.pos.x = 0;
//	data->cam.pos.y = 0;
//	data->cam.pos.z = 0;

//	l = от p до источника света
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
		p = vec3_plus(vec3_mult_num(d, min_dist), data->cam.pos);
		l = vec3_minus(p, data->light->coord);
		normal = data->find_normal[obj->type](obj, &d, p);
		float light_intence = vec3_dot(vec3_normalize(l), normal) / (vec3_len(normal) * vec3_len(l));
//		light_intence += 0.5;
		data->mlx.data[x + H_WIDTH + (y + H_HEIGHT) * WIDTH] = vec3_to_color(vec3_mult_num(obj->color, light_intence));

//		printf("%f\n", light_intence);
//		float light_intence = vec3_normalize(l) * normal / (|l| * |normal|);
//		color_res = light_intence * obj_color;
//
//		data->mlx.data[x + H_WIDTH + (y + H_HEIGHT) * WIDTH] = vec3_to_color(obj->color);
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

