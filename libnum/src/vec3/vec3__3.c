/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3__3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:35 by kcharla           #+#    #+#             */
/*   Updated: 2020/07/19 15:12:33 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec3	vec3(t_num x, t_num y, t_num z)
{
	return ((t_vec3){x, y, z});
}

t_vec3	vec3_zero(void)
{
	return ((t_vec3){0, 0, 0});
}

int		vec3_is_zero(t_vec3 a)
{
	return (a.x == 0 && a.y == 0 && a.z == 0);
}

int		vec3_is_inf(t_vec3 a)
{
	return (isinf(a.x) || isinf(a.y) || isinf(a.z));
}

t_vec3	vec3_inf(void)
{
	return ((t_vec3){INFINITY, INFINITY, INFINITY});
}
