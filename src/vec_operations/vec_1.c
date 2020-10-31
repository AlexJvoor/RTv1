/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:30:03 by hchau             #+#    #+#             */
/*   Updated: 2020/10/23 15:30:16 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		vec3_plus(t_vec3 a, t_vec3 b)
{
	t_vec3		res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vec3		vec3_minus(t_vec3 a, t_vec3 b)
{
	t_vec3		res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vec3		vec3_mult(t_vec3 a, t_vec3 b)
{
	t_vec3		res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

t_vec3		vec3_div(t_vec3 a, t_vec3 b)
{
	t_vec3		res;

	res.x = a.x / b.x;
	res.y = a.y / b.y;
	res.z = a.z / b.z;
	return (res);
}

t_vec3		vec3_sqr(t_vec3 a)
{
	t_vec3		res;

	res.x = a.x * a.x;
	res.y = a.y * a.y;
	res.z = a.z * a.z;
	return (res);
}
