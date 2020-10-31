/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:22:20 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/23 10:22:22 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		rotate_cam(t_vec3 viewport, t_cam cam)
{
	t_vec3		x_rot;
	t_vec3		y_rot;
	t_vec3		z_rot;

	x_rot.x = viewport.x;
	x_rot.y = viewport.y * cos(cam.dir.z) + viewport.z * -sin(cam.dir.z);
	x_rot.z = viewport.y * sin(cam.dir.z) + viewport.z * cos(cam.dir.z);
	y_rot.x = x_rot.x * cos(cam.dir.x) + x_rot.z * sin(cam.dir.x);
	y_rot.y = x_rot.y;
	y_rot.z = x_rot.x * -sin(cam.dir.x) + x_rot.z * cos(cam.dir.x);
	z_rot.x = y_rot.x * cos(cam.dir.y) + y_rot.y * -sin(cam.dir.y);
	z_rot.y = y_rot.x * sin(cam.dir.y) + y_rot.y * cos(cam.dir.y);
	z_rot.z = y_rot.z;
	return (z_rot);
}

t_vec3		eye_trace(int x, int y, t_cam *cam)
{
	return (vec3_normalize(vec3_minus(rotate_cam((t_vec3){(x) * (VX),
		(y) * (VY), 1.0}, *cam), cam->pos)));
}

t_trace		get_trace(t_vec3 d, t_num min_dist, t_data *data, t_obj *obj)
{
	t_trace		trace;

	trace.d = d;
	trace.min_dist = min_dist;
	trace.p = vec3_plus(vec3_mult_num(d, min_dist), data->cam.pos);
	trace.normal = obj->find_normal(obj, &d, min_dist, data->cam);
	trace.obj_col = obj->color;
	return (trace);
}

int			final_color(t_data *data, t_obj *obj, t_num min_dist, t_vec3 d)
{
	t_light		*tmp;
	t_vec3		color;
	t_trace		trace;

	trace = get_trace(d, min_dist, data, obj);
	tmp = data->light;
	color.x = 0;
	color.y = 0;
	color.z = 0;
	if (data->texture_my_sphere == TRUE)
		trace.obj_col = find_textel(data, trace.p, obj);
	while (tmp)
	{
		color = vec3_plus(curr_color(obj, trace, tmp, data), color);
		tmp = tmp->next;
	}
	return (vec3_to_color(color));
}

void		draw_figure(int x, int y, t_data *data)
{
	t_list		*tmp;
	t_vec3		d;
	t_num		dist;
	t_num		min_dist;
	t_obj		*obj;

	min_dist = INFINITY;
	d = eye_trace(x, y, &data->cam);
	tmp = data->objs;
	while (tmp)
	{
		dist = data->find_destination[(*(t_obj **)tmp->content)->type](
				*(t_obj **)tmp->content, &d, &data->cam.pos);
		if (dist > 0.00001 && dist < INFINITY && dist < min_dist)
		{
			min_dist = dist;
			obj = *(t_obj **)tmp->content;
		}
		tmp = tmp->next;
	}
	if (min_dist != INFINITY)
		data->mlx.data[x + H_WIDTH + (y + H_HEIGHT) * WIDTH] =
				final_color(data, obj, min_dist, d);
	else
		data->mlx.data[x + H_WIDTH + (y + H_HEIGHT) * WIDTH] = 0;
}
