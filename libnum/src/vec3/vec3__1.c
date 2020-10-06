/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3__1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:37:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/07/19 15:11:04 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec3		vec3_plus(t_vec3 a, t_vec3 b)
{
	return (vec3_do_vec3(a, b, num_plus));
}

t_vec3		vec3_minus(t_vec3 a, t_vec3 b)
{
	return (vec3_do_vec3(a, b, num_minus));
}

t_vec3		vec3_mult(t_vec3 a, t_vec3 b)
{
	return (vec3_do_vec3(a, b, num_mult));
}

t_vec3		vec3_div(t_vec3 a, t_vec3 b)
{
	return (vec3_do_vec3(a, b, num_div));
}

t_vec3		vec3_sqr(t_vec3 a)
{
	return (vec3_do_vec3(a, a, num_mult));
}
