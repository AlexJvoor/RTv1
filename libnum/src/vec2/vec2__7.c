/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2__7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 21:24:30 by hush              #+#    #+#             */
/*   Updated: 2020/07/19 15:57:20 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

int				vec2_point_is_behind(t_vec2 vec_from_zero, t_vec2 point)
{
	if (vec2_sum(vec2_mult(vec_from_zero, point)) < 0)
		return (1);
	return (0);
}

t_vec2			vec2_clamp(t_vec2 source, t_num min, t_num max)
{
	source.x = num_clamp(source.x, min, max);
	source.y = num_clamp(source.y, min, max);
	return (source);
}

t_vec2			vec2_max_num(t_vec2 v, t_num n)
{
	return (vec2_max(v, vec2(n, n)));
}

t_vec2			vec2_min_num(t_vec2 v, t_num n)
{
	return (vec2_min(v, vec2(n, n)));
}
