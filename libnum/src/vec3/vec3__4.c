/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3__4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 11:48:52 by hush              #+#    #+#             */
/*   Updated: 2020/07/19 15:13:49 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec3		vec3_invert(t_vec3 vector)
{
	return (vec3_mult_num(vector, -1));
}

t_vec3		vec3_normalize(t_vec3 vec)
{
	return (vec3_do_num(vec, vec3_len(vec), num_div));
}

t_num		vec3_dot(t_vec3 a, t_vec3 b)
{
	return (vec3_sum(vec3_mult(a, b)));
}

t_vec3		vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	vp;

	vp.x = a.y * b.z - b.y * a.z;
	vp.y = a.z * b.x - b.z * a.x;
	vp.z = a.x * b.y - b.x * a.y;
	return (vp);
}

t_num		vec3_angle_cos(t_vec3 a, t_vec3 b)
{
	return (vec3_dot(vec3_normalize(a), vec3_normalize(b)));
}
