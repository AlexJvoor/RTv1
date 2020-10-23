/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:30:32 by hchau             #+#    #+#             */
/*   Updated: 2020/10/23 15:30:43 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		vec3_plus_num(t_vec3 v, t_num n)
{
	t_vec3		res;

	res.x = v.x + n;
	res.y = v.y + n;
	res.z = v.z + n;
	return (res);
}

t_vec3		vec3_minus_num(t_vec3 v, t_num n)
{
	t_vec3		res;

	res.x = v.x - n;
	res.y = v.y - n;
	res.z = v.z - n;
	return (res);
}

t_vec3		vec3_mult_num(t_vec3 v, t_num n)
{
	t_vec3		res;

	res.x = v.x * n;
	res.y = v.y * n;
	res.z = v.z * n;
	return (res);
}

t_vec3		vec3_div_num(t_vec3 v, t_num n)
{
	t_vec3		res;

	res.x = v.x / n;
	res.y = v.y / n;
	res.z = v.z / n;
	return (res);
}

t_num		vec3_sum(t_vec3 v)
{
	return (v.x + v.y + v.z);
}
