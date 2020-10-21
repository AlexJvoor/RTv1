/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:16:46 by hchau             #+#    #+#             */
/*   Updated: 2020/10/21 16:16:57 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				vec3_to_color(t_vec3 vec)
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
	color = 0 << 24 | (int)res_vec.x << 16 |
			(int)res_vec.y << 8 | (int)res_vec.z;
	return (color);
}

static t_vec3	light_cast(t_vec3 light_col, t_vec3 l, t_vec3 normal)
{
	t_vec3		res;

	res = vec3_mult_num(light_col,
		vec3_dot(vec3_normalize(l), normal) /
		(vec3_len(normal) * vec3_len(l)));
	return (res);
}

int				is_shadowed(t_data *data, t_obj *obj, t_vec3 u, t_vec3 *p)
{
	t_list		*tmp;
	t_num		dist;
	t_vec3		norm_l;
	t_num		dist_l;
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
		dist = data->find_destination[(*(t_obj **)tmp->content)->type](data,
			*(t_obj **)tmp->content, &norm_l, p);
		if (dist > 0 && dist < dist_l)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_vec3			curr_color(t_obj *obj, t_trace trace,
					t_light *light, t_data *data)
{
	t_vec3		l;
	t_vec3		res;
	t_vec3		b_vec_res;

	l = vec3_minus(trace.p, light->coord);
	if (vec3_dot(trace.d, l) < 0)
		return (t_vec3){0.0, 0.0, 0.0};
	if (is_shadowed(data, obj, light->coord, &trace.p))
		return ((t_vec3){0.0, 0.0, 0.0});
	res = vec3_mult_num(light_cast(light->color,
		l, trace.normal), light->light_pov);
	b_vec_res = vec3_mult_num(obj->bright_cast(light->color,
				l, trace.normal, (int)obj->shine), light->light_pov);
	return (vec3_plus(vec3_mult(trace.obj_col, res), b_vec_res));
}
