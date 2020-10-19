//
// Created by Hugor Chau on 10/8/20.
//

#include "rtv1.h"

int			vec3_to_color(t_vec3 vec)
{
	t_vec3		res_vec;
	int			color;

	res_vec = vec3_mult_num(vec, 255);
	res_vec.x = res_vec.x > 255 ? 255 : res_vec.x;
	res_vec.y = res_vec.y > 255 ? 255 : res_vec.y;
	res_vec.z = res_vec.z > 255 ? 255 : res_vec.z;
	res_vec.x = res_vec.x < 1 ? 0 : res_vec.x;
	res_vec.y = res_vec.y < 1 ? 0 : res_vec.y;
	res_vec.z = res_vec.z < 1 ? 0 : res_vec.z;
	color = 0 << 24 | (int)res_vec.x << 16 | (int)res_vec.y << 8 | (int)res_vec.z;
	return (color);
}

static t_vec3		light_cast(t_vec3 light_col, t_vec3 l, t_vec3 normal)
{
	t_vec3		res;

	res = vec3_mult_num(light_col, vec3_dot(vec3_normalize(l), normal) / (vec3_len(normal) * vec3_len(l)));
	return (res);
}

t_vec3		bright_cast(t_vec3 light_col, t_vec3 l, t_vec3 normal, float shine)
{
	t_vec3		b_vec_res;
	float		nl;
	t_vec3		r;
	float		blick_res;

	nl = vec3_dot(normal, l);
	r = vec3_plus(vec3_minus(vec3_mult_num(normal, nl), l), vec3_mult_num(normal, nl));
	blick_res = vec3_dot(r, normal) / (vec3_len(normal) * vec3_len(r));
	b_vec_res = (vec3_mult_num(light_col, pow(blick_res, (int)shine)));
	return (b_vec_res);
}

t_vec3		bright_cast2(t_vec3 light_col, t_vec3 l, t_vec3 normal, float shine)
{
	float		nl;

	nl = vec3_dot(normal, l);
	return (vec3_mult_num(normal, nl * 0.5));
}

t_vec3		bright_cast3(t_vec3 light_col, t_vec3 l, t_vec3 normal, float shine)
{
	float		nl;

	nl = vec3_dot(normal, l) * -1;
	return (vec3_mult_num(normal, nl * 0.5));
}

t_vec3		bright_cast4(t_vec3 light_col, t_vec3 l, t_vec3 normal, float shine)
{
	float		nl;

	nl = vec3_dot(normal, l);
	return (vec3_mult_num(vec3_mult_num(light_col, pow(nl, (int)shine)), 0.005));
}
//
//t_vec3		bright_cast5(t_vec3 light_col, t_vec3 l, t_vec3 normal, float shine)
//{
//	t_vec3		b_vec_res;
//	float		nl;
//	t_vec3		r;
//	float		blick_res;
//
//	nl = vec3_dot(normal, l);
//	r = vec3_plus(vec3_minus(vec3_mult_num(normal, nl), l), vec3_mult_num(normal, nl));
//	blick_res = vec3_dot(r, normal) / (vec3_len(normal) * vec3_len(r));
//	b_vec_res = vec3_mult_num(vec3_mult_num(light_col, pow(blick_res, (int)shine)), -1);
//	return (b_vec_res);
//}

int			is_shadowed(t_data *data, t_obj *obj, t_vec3 u, t_vec3 *p)
{
	t_list		*tmp;
	float		dist;
	t_vec3		norm_l;
	float		dist_l;
	t_vec3		l;

	l = vec3_minus(u, *p);
	norm_l = vec3_normalize(l);
	dist_l = vec3_len(l);
	tmp = data->objs;
	while (tmp)
	{
		if (*(void **)(tmp->content) == obj)
		{
			tmp = tmp->next;
			continue ;
		}
		dist = data->find_destination[(*(t_obj **)tmp->content)->type](data, *(t_obj **)tmp->content, &norm_l, p);
		if (dist > 0 && dist < dist_l)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_vec3		curr_color(t_obj *obj, t_vec3 d, t_light *light, float min_dist, t_data *data)
{
	t_vec3		l;
	t_vec3		normal;
	t_vec3		res;
	t_vec3		b_vec_res;
//	t_vec3		shadowed;
	t_vec3		p;

	p = vec3_plus(vec3_mult_num(d, min_dist), data->cam.pos);
	l = vec3_minus(p, light->coord);
//	shadowed = (t_vec3){0.0, 0.0, 0.0};
	if (is_shadowed(data, obj, light->coord, &p))
	{
		return ((t_vec3){0.0, 0.0, 0.0});
//		shadowed = (t_vec3){-0.2 * light->light_pov, -0.2 * light->light_pov, -0.2 * light->light_pov};
	}
	normal = obj->find_normal(obj, &d, min_dist,data->cam);
	res = vec3_mult_num(light_cast(light->color, l, normal), light->light_pov);
	b_vec_res = vec3_mult_num(obj->bright_cast(light->color, l, normal, (int)obj->shine), light->light_pov);
//	return (vec3_plus(vec3_plus(vec3_mult(obj->color, res), b_vec_res), shadowed));
	return (vec3_plus(vec3_mult(obj->color, res), b_vec_res));
}
