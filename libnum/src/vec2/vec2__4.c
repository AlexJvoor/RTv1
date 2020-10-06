/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2__4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 11:48:52 by hush              #+#    #+#             */
/*   Updated: 2020/07/19 15:29:17 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec2		vec2_invert(t_vec2 vector)
{
	return (vec2_mult_num(vector, -1));
}

t_vec2		vec2_normalize(t_vec2 vec)
{
	return (vec2_do_num(vec, vec2_len(vec), num_div));
}

t_num		vec2_dot(t_vec2 a, t_vec2 b)
{
	return (vec2_sum(vec2_mult(a, b)));
}

/*
**t_vec2		vec2_cross(t_vec2 a, t_vec2 b)
**{
**	t_vec2	vp;
**
**	vp.x = a.y * b.z - b.y * a.z;
**	vp.y = a.z * b.x - b.z * a.x;
**	vp.z = a.x * b.y - b.x * a.y;
**	return (vp);
**}
*/

t_num		vec2_angle_cos(t_vec2 a, t_vec2 b)
{
	return (vec2_dot(vec2_normalize(a), vec2_normalize(b)));
}
