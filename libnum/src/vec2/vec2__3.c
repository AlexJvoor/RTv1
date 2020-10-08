/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2__3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:35 by kcharla           #+#    #+#             */
/*   Updated: 2020/07/19 15:21:59 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec2	vec2(t_num x, t_num y)
{
	return ((t_vec2){x, y});
}

t_vec2	vec2_zero(void)
{
	return ((t_vec2){0, 0});
}

int		vec2_is_zero(t_vec2 a)
{
	return (a.x == 0 && a.y == 0);
}

int		vec2_is_inf(t_vec2 a)
{
	return (isinf(a.x) || isinf(a.y));
}

t_vec2	vec2_inf(void)
{
	return ((t_vec2){INFINITY, INFINITY});
}
