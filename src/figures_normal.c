/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:30:06 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/23 13:30:08 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		sphere_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam)
{
	t_vec3 p;

	p = vec3_plus(vec3_mult_num(*d, min_dist), cam.pos);
	return (vec3_normalize(vec3_minus(((t_sphere *)obj)->coords, p)));
}

t_vec3		plane_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam)
{
	return (((t_plane *)obj)->norm);
}

t_vec3		get_cone_preparations(t_obj *obj, t_vec3 *d,
							t_num min_dist, t_cam cam)
{
	t_vec3	p;
	t_vec3	p_c;

	p = vec3_plus(cam.pos, vec3_mult_num(*d, min_dist));
	p_c = vec3_minus(p, ((t_cone*)obj)->coords);
	return (p_c);
}

t_vec3		cone_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam)
{
	t_vec3	v;
	t_vec3	oc;
	t_num	m;
	t_num	k;
	t_vec3	p_c;

	k = tan((((t_cone*)obj)->tg));
	v = vec3_normalize(((t_cone*)obj)->dir_vec);
	oc = vec3_minus(cam.pos, ((t_cone*)obj)->coords);
	m = vec3_dot(*d, v) * min_dist + vec3_dot(oc, v);
	p_c = get_cone_preparations(obj, d, min_dist, cam);
	return (vec3_normalize(vec3_minus(vec3_mult_num(v, m * (1 + k * k)), p_c)));
}

t_vec3		cylinder_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam)
{
	t_vec3	v_ar[5];
	t_num	m;

	v_ar[0] = vec3_normalize(((t_cylinder*)obj)->dir_vec);
	v_ar[1] = vec3_minus(cam.pos, ((t_cylinder*)obj)->coords);
	m = vec3_dot(*d, vec3_mult_num(v_ar[0],
							min_dist)) + vec3_dot(v_ar[1], v_ar[0]);
	v_ar[2] = vec3_plus(vec3_mult_num(*d, min_dist), cam.pos);
	v_ar[3] = vec3_minus(v_ar[2], ((t_cylinder*)obj)->coords);
	v_ar[4] = vec3_mult_num(v_ar[0], m);
	return (vec3_normalize(vec3_minus(v_ar[4], v_ar[3])));
}
