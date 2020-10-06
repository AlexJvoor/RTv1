/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2__6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:29:24 by hush              #+#    #+#             */
/*   Updated: 2020/07/19 15:43:55 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec2		vec2_do_vec2(t_vec2 v1, t_vec2 v2, t_num f(t_num n1, t_num n2))
{
	v1.x = f(v1.x, v2.x);
	v1.y = f(v1.y, v2.y);
	return (v1);
}

t_vec2		vec2_do_num(t_vec2 v, t_num n, t_num f(t_num n1, t_num n2))
{
	v.x = f(v.x, n);
	v.y = f(v.y, n);
	return (v);
}

t_vec2		vec2_swap(t_vec2 v)
{
	return ((t_vec2){v.y, v.x});
}