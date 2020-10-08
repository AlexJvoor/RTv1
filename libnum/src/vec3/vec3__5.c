/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3__5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:09:01 by hush              #+#    #+#             */
/*   Updated: 2020/07/19 15:15:41 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_num		vec3_dist_sqr(t_vec3 a, t_vec3 b)
{
	return (vec3_sum(vec3_sqr(vec3_minus(a, b))));
}

t_num		vec3_dist(t_vec3 a, t_vec3 b)
{
	return (sqrt(vec3_dist_sqr(a, b)));
}

t_num		vec3_len(t_vec3 a)
{
	return (vec3_dist(vec3_zero(), a));
}

t_vec3		vec3_max(t_vec3 a, t_vec3 b)
{
	return (vec3_do_vec3(a, b, num_max));
}

t_vec3		vec3_min(t_vec3 a, t_vec3 b)
{
	return (vec3_do_vec3(a, b, num_min));
}
