/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons_variants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:21:38 by hchau             #+#    #+#             */
/*   Updated: 2020/10/21 16:21:43 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3				bright_cast(t_vec3 light_col,
								t_vec3 l, t_vec3 normal, t_num shine)
{
	t_vec3		b_vec_res;
	t_num		nl;
	t_vec3		r;
	t_num		blick_res;

	nl = vec3_dot(normal, l);
	r = vec3_plus(vec3_minus(vec3_mult_num(normal, nl), l),
			vec3_mult_num(normal, nl));
	blick_res = vec3_dot(r, normal) / (vec3_len(normal) * vec3_len(r));
	b_vec_res = (vec3_mult_num(light_col, pow(blick_res, (int)shine)));
	return (b_vec_res);
}

t_vec3				bright_cast2(t_vec3 light_col,
								t_vec3 l, t_vec3 normal, t_num shine)
{
	t_num		nl;

	nl = vec3_dot(normal, l);
	light_col = (t_vec3){0.0, 0.0, 0.0};
	shine = 0;
	return (vec3_mult_num(normal, nl * 0.5));
}

t_vec3				bright_cast3(t_vec3 light_col,
								t_vec3 l, t_vec3 normal, t_num shine)
{
	t_num		nl;

	nl = vec3_dot(normal, l) * -1;
	light_col = (t_vec3){0.0, 0.0, 0.0};
	shine = 0;
	return (vec3_mult_num(normal, nl * 0.5));
}
