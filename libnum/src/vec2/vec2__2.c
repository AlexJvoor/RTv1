/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2__2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:53 by kcharla           #+#    #+#             */
/*   Updated: 2020/07/19 15:21:15 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec2		vec2_plus_num(t_vec2 v, t_num n)
{
	return (vec2_do_num(v, n, num_plus));
}

t_vec2		vec2_minus_num(t_vec2 v, t_num n)
{
	return (vec2_do_num(v, n, num_minus));
}

t_vec2		vec2_mult_num(t_vec2 v, t_num n)
{
	return (vec2_do_num(v, n, num_mult));
}

t_vec2		vec2_div_num(t_vec2 v, t_num n)
{
	return (vec2_do_num(v, n, num_div));
}

t_num		vec2_sum(t_vec2 v)
{
	return (v.x + v.y);
}
