/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3__2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:53 by kcharla           #+#    #+#             */
/*   Updated: 2020/07/19 15:11:35 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec3		vec3_plus_num(t_vec3 v, t_num n)
{
	return (vec3_do_num(v, n, num_plus));
}

t_vec3		vec3_minus_num(t_vec3 v, t_num n)
{
	return (vec3_do_num(v, n, num_minus));
}

t_vec3		vec3_mult_num(t_vec3 v, t_num n)
{
	return (vec3_do_num(v, n, num_mult));
}

t_vec3		vec3_div_num(t_vec3 v, t_num n)
{
	return (vec3_do_num(v, n, num_div));
}

t_num		vec3_sum(t_vec3 v)
{
	return (v.x + v.y + v.z);
}
