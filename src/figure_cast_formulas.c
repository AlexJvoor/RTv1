/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_cast_formulas.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:49:00 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/23 10:49:01 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_num			sphere_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *cam)
{
	t_num		n_ar[7];
	t_vec3		c;
	t_vec3		oc;

	c = ((t_sphere *)obj)->coords;
	oc = vec3_minus(*cam, c);
	n_ar[0] = ((t_sphere *)obj)->rad;
	n_ar[1] = vec3_dot(*d, *d);
	n_ar[2] = 2 * vec3_dot(oc, *d);
	n_ar[3] = vec3_dot(oc, oc) - n_ar[0] * n_ar[0];
	n_ar[4] = n_ar[2] * n_ar[2] - 4 * n_ar[1] * n_ar[3];
	if (n_ar[4] < 0)
		return (INFINITY);
	n_ar[5] = (-n_ar[2] + sqrt(n_ar[4])) / (2 * n_ar[1]);
	n_ar[6] = (-n_ar[2] - sqrt(n_ar[4])) / (2 * n_ar[1]);
	return (n_ar[5] < n_ar[6] ? n_ar[5] : n_ar[6]);
}

t_num			cone_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *cam)
{
	t_vec3		oc;
	t_num		n_ar[9];
	t_num		k;

	oc = vec3_minus(*cam, ((t_cone *)obj)->coords);
	n_ar[0] = vec3_dot(*d, ((t_cone *)obj)->dir_vec);
	n_ar[1] = vec3_dot(oc, ((t_cone *)obj)->dir_vec);
	k = tan((((t_cone*)obj)->tg));
	k = k * k + 1.0;
	n_ar[2] = vec3_dot(*d, *d) - k * pow(n_ar[0], 2.0);
	n_ar[3] = 2.0 * (vec3_dot(*d, oc) - k * n_ar[1] * n_ar[0]);
	n_ar[4] = vec3_dot(oc, oc) - k * pow(n_ar[1], 2.0);
	n_ar[5] = n_ar[3] * n_ar[3] - 4 * n_ar[2] * n_ar[4];
	if (n_ar[5] < 0)
		return (INFINITY);
	n_ar[6] = (-n_ar[3] + sqrt(n_ar[5])) / (2 * n_ar[2]);
	n_ar[7] = (-n_ar[3] - sqrt(n_ar[5])) / (2 * n_ar[2]);
	if (n_ar[6] < n_ar[7] && n_ar[6] > 0)
		return (n_ar[6]);
	if (n_ar[7] < n_ar[6] && n_ar[7] > 0)
		return (n_ar[7]);
	return (INFINITY);
}

t_num			plane_cast(t_data *data, t_obj *obj, t_vec3 *d_old, t_vec3 *cam)
{
	t_num		t;
	t_num		vx;
	t_vec3		x;
	t_vec3		d;

	d = vec3_normalize(*d_old);
	x = vec3_minus(*cam, ((t_plane *)obj)->coords);
	vx = vec3_dot(x, ((t_plane *)obj)->norm) * -1;
	t = vx / vec3_dot(d, ((t_plane *)obj)->norm);
	return (t);
}

t_num			cylinder_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *cam)
{
	t_vec3		oc;
	t_vec3		v;
	t_num		n_ar[6];

	oc = vec3_minus(*cam, ((t_cylinder*)obj)->coords);
	v = vec3_normalize(((t_cylinder*)obj)->dir_vec);
	n_ar[0] = vec3_dot(*d, *d) - pow(vec3_dot(*d, v), 2);
	n_ar[1] = 2 * (vec3_dot(*d, oc) - vec3_dot(*d, v) * vec3_dot(oc, v));
	n_ar[2] = vec3_dot(oc, oc) - pow(vec3_dot(oc, v),
								2) - pow(((t_cylinder*)obj)->rad, 2);
	n_ar[3] = n_ar[1] * n_ar[1] - 4 * n_ar[0] * n_ar[2];
	if (n_ar[3] < 0)
		return (INFINITY);
	n_ar[4] = (-n_ar[1] + sqrt(n_ar[3])) / (2 * n_ar[0]);
	n_ar[5] = (-n_ar[1] - sqrt(n_ar[3])) / (2 * n_ar[0]);
	return (n_ar[4] < n_ar[5] ? n_ar[4] : n_ar[5]);
}
