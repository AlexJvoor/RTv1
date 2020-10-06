/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3__6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:29:24 by hush              #+#    #+#             */
/*   Updated: 2020/07/19 15:14:45 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec3		vec3_do_vec3(t_vec3 v1, t_vec3 v2, t_num f(t_num n1, t_num n2))
{
	v1.x = f(v1.x, v2.x);
	v1.y = f(v1.y, v2.y);
	v1.z = f(v1.z, v2.z);
	return (v1);
}

t_vec3		vec3_do_num(t_vec3 v, t_num n, t_num f(t_num n1, t_num n2))
{
	v.x = f(v.x, n);
	v.y = f(v.y, n);
	v.z = f(v.z, n);
	return (v);
}
