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
	res_vec.x = res_vec.x < 0 ? 0 : res_vec.x;
	res_vec.y = res_vec.y < 0 ? 0 : res_vec.y;
	res_vec.z = res_vec.z < 0 ? 0 : res_vec.z;
	color = 0 << 24 | (int)res_vec.x << 16 | (int)res_vec.y << 8 | (int)res_vec.z;
	return (color);
}

static t_vec3		light_cast(t_vec3 light_col, t_vec3 l, t_vec3 normal)
{
	t_vec3		res;

	res = vec3_mult_num(light_col, vec3_dot(vec3_normalize(l), normal) / (vec3_len(normal) * vec3_len(l)));
	return (res);
}

static t_vec3		bright_cast(t_vec3 light_col, t_vec3 l, t_vec3 normal, float shine)
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

t_vec3		curr_color(t_obj *obj, t_vec3 d, t_light *light, t_vec3 p)
{
	t_vec3		l;
	t_vec3		normal;
	t_vec3		res;
	t_vec3		b_vec_res;

	l = vec3_minus(p, light->coord);
	normal = obj->find_normal(obj, &d, p);
	res = light_cast(light->color, l, normal);
	b_vec_res = bright_cast(light->color, l, normal, (int)obj->shine);
	return (vec3_plus(vec3_mult(obj->color, res), b_vec_res));
}
