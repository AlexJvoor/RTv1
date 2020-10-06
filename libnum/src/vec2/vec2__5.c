/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2__5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:09:01 by hush              #+#    #+#             */
/*   Updated: 2020/07/19 15:40:46 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_num		vec2_dist_sqr(t_vec2 a, t_vec2 b)
{
	return (vec2_sum(vec2_sqr(vec2_minus(a, b))));
}

t_num		vec2_dist(t_vec2 a, t_vec2 b)
{
	return (sqrt(vec2_dist_sqr(a, b)));
}

t_num		vec2_len(t_vec2 a)
{
	return (vec2_dist(vec2_zero(), a));
}

t_vec2		vec2_max(t_vec2 a, t_vec2 b)
{
	return (vec2_do_vec2(a, b, num_max));
}

t_vec2		vec2_min(t_vec2 a, t_vec2 b)
{
	return (vec2_do_vec2(a, b, num_min));
}
