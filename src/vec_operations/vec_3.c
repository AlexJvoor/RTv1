/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:30:52 by hchau             #+#    #+#             */
/*   Updated: 2020/10/23 15:31:02 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		vec3_invert(t_vec3 vector)
{
	return (vec3_mult_num(vector, -1));
}

t_vec3		vec3_normalize(t_vec3 vec)
{
	t_vec3		res;
	t_num		vec_len;

	vec_len = vec3_len(vec);
	res.x = vec.x / vec_len;
	res.y = vec.y / vec_len;
	res.z = vec.z / vec_len;
	return (res);
}

t_num		vec3_dot(t_vec3 a, t_vec3 b)
{
	t_vec3		res;

	res.x = (a.x * b.x);
	res.y = (a.y * b.y);
	res.z = (a.z * b.z);
	return (res.x + res.y + res.z);
}

t_vec3		vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	vp;

	vp.x = a.y * b.z - b.y * a.z;
	vp.y = a.z * b.x - b.z * a.x;
	vp.z = a.x * b.y - b.x * a.y;
	return (vp);
}

t_num		vec3_len(t_vec3 a)
{
	t_num		res;

	res = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	return (res);
}
