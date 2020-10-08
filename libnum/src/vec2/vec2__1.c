/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2__1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:37:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/07/19 15:18:09 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec2		vec2_plus(t_vec2 a, t_vec2 b)
{
	return (vec2_do_vec2(a, b, num_plus));
}

t_vec2		vec2_minus(t_vec2 a, t_vec2 b)
{
	return (vec2_do_vec2(a, b, num_minus));
}

t_vec2		vec2_mult(t_vec2 a, t_vec2 b)
{
	return (vec2_do_vec2(a, b, num_mult));
}

t_vec2		vec2_div(t_vec2 a, t_vec2 b)
{
	return (vec2_do_vec2(a, b, num_div));
}

t_vec2		vec2_sqr(t_vec2 a)
{
	return (vec2_do_vec2(a, a, num_mult));
}
