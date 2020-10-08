/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3__7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 21:24:30 by hush              #+#    #+#             */
/*   Updated: 2020/07/19 15:15:37 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

int				vec3_point_is_behind(t_vec3 vec_from_zero, t_vec3 point)
{
	if (vec3_sum(vec3_mult(vec_from_zero, point)) < 0)
		return (1);
	return (0);
}

t_vec3			vec3_clamp(t_vec3 source, t_num min, t_num max)
{
	source.x = num_clamp(source.x, min, max);
	source.y = num_clamp(source.y, min, max);
	source.z = num_clamp(source.z, min, max);
	return (source);
}

t_vec3			vec3_max_num(t_vec3 v, t_num n)
{
	return (vec3_max(v, vec3(n, n, n)));
}

t_vec3			vec3_min_num(t_vec3 v, t_num n)
{
	return (vec3_min(v, vec3(n, n, n)));
}
