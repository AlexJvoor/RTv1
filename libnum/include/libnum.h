 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnum.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 03:06:49 by kcharla           #+#    #+#             */
/*   Updated: 2020/07/19 15:56:50 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNUM_H
# define LIBNUM_H

# include <math.h>

typedef float		t_num;

typedef struct		s_vec2
{
	t_num			x;
	t_num			y;
}					t_vec2;

typedef struct		s_vec3
{
	t_num			x;
	t_num			y;
	t_num			z;
}					t_vec3;

/*
** num__1.c
*/

t_num		num_plus(t_num a, t_num b);
t_num		num_minus(t_num a, t_num b);
t_num		num_mult(t_num a, t_num b);
t_num		num_div(t_num a, t_num b);
t_num		num_sqr(t_num a);

/*
** num__2.c
*/

t_num		num_min(t_num a, t_num b);
t_num		num_max(t_num a, t_num b);
t_num		num_clamp(t_num val, t_num min, t_num max);
t_num		num_map(t_num x, t_vec2 in, t_vec2 out);

/* ************************************************************************** */
/*                                 vec2                                       */
/* ************************************************************************** */

/*
** vec2__1.c
*/

t_vec2				vec2_plus(t_vec2 a, t_vec2 b);
t_vec2				vec2_minus(t_vec2 a, t_vec2 b);
t_vec2				vec2_mult(t_vec2 a, t_vec2 b);
t_vec2				vec2_div(t_vec2 a, t_vec2 b);
t_vec2				vec2_sqr(t_vec2 a);

/*
** vec2__2.c
*/

t_vec2				vec2_plus_num(t_vec2 v, t_num n);
t_vec2				vec2_minus_num(t_vec2 v, t_num n);
t_vec2				vec2_mult_num(t_vec2 v, t_num n);
t_vec2				vec2_div_num(t_vec2 v, t_num n);
t_num				vec2_sum(t_vec2 v);

/*
** vec2__3.c
*/

t_vec2				vec2(t_num x, t_num y);
t_vec2				vec2_zero();
int					vec2_is_zero(t_vec2 a);
t_vec2				vec2_inf();
int					vec2_is_inf(t_vec2 a);

/*
** vec2__4.c
*/

t_vec2				vec2_invert(t_vec2 vector);
t_vec2				vec2_normalize(t_vec2 vector);
t_num				vec2_dot(t_vec2 a, t_vec2 b);
/*
**t_vec2				vec2_cross(t_vec2 a, t_vec2 b);
*/
t_num				vec2_angle_cos(t_vec2 a, t_vec2 b);

/*
** vec2__5.c
*/

t_num				vec2_dist_sqr(t_vec2 a, t_vec2 b);
t_num				vec2_dist(t_vec2 a, t_vec2 b);
t_num				vec2_len(t_vec2 a);
t_vec2				vec2_max(t_vec2 a, t_vec2 b);
t_vec2				vec2_min(t_vec2 a, t_vec2 b);

/*
** vec2__6.c
*/

t_vec2				vec2_do_vec2(t_vec2 v1, t_vec2 v2, t_num f(t_num n1, t_num n2));
t_vec2				vec2_do_num(t_vec2 v, t_num n, t_num f(t_num n1, t_num n2));
t_vec2				vec2_swap(t_vec2 v);

/*
** vec2__7.c
*/

int					vec2_point_is_behind(t_vec2 vec2_from_zero, t_vec2 point);
t_vec2				vec2_clamp(t_vec2 source, t_num min, t_num max);
t_vec2				vec2_max_num(t_vec2 v, t_num n);
t_vec2				vec2_max_min(t_vec2 v, t_num n);

/* ************************************************************************** */
/*                                 vec3                                       */
/* ************************************************************************** */

/*
** vec3__1.c
*/

t_vec3				vec3_plus(t_vec3 a, t_vec3 b);
t_vec3				vec3_minus(t_vec3 a, t_vec3 b);
t_vec3				vec3_mult(t_vec3 a, t_vec3 b);
t_vec3				vec3_div(t_vec3 a, t_vec3 b);
t_vec3				vec3_sqr(t_vec3 a);

/*
** vec3__2.c
*/

t_vec3				vec3_plus_num(t_vec3 v, t_num n);
t_vec3				vec3_minus_num(t_vec3 v, t_num n);
t_vec3				vec3_mult_num(t_vec3 v, t_num n);
t_vec3				vec3_div_num(t_vec3 v, t_num n);
t_num				vec3_sum(t_vec3 v);

/*
** vec3__3.c
*/

t_vec3				vec3(t_num x, t_num y, t_num z);
t_vec3				vec3_zero();
int					vec3_is_zero(t_vec3 a);
t_vec3				vec3_inf();
int					vec3_is_inf(t_vec3 a);

/*
** vec3__4.c
*/

t_vec3				vec3_invert(t_vec3 vector);
t_vec3				vec3_normalize(t_vec3 vector);
t_num				vec3_dot(t_vec3 a, t_vec3 b);
t_vec3				vec3_cross(t_vec3 a, t_vec3 b);
t_num				vec3_angle_cos(t_vec3 a, t_vec3 b);

/*
** vec3__5.c
*/

t_num				vec3_dist_sqr(t_vec3 a, t_vec3 b);
t_num				vec3_dist(t_vec3 a, t_vec3 b);
t_num				vec3_len(t_vec3 a);
t_vec3				vec3_max(t_vec3 a, t_vec3 b);
t_vec3				vec3_min(t_vec3 a, t_vec3 b);

/*
** vec3__6.c
*/

t_vec3				vec3_do_vec3(t_vec3 v1, t_vec3 v2, t_num f(t_num n1, t_num n2));
t_vec3				vec3_do_num(t_vec3 v, t_num n, t_num f(t_num n1, t_num n2));

/*
** vec3__7.c
*/

int					vec3_point_is_behind(t_vec3 vec3_from_zero, t_vec3 point);
t_vec3				vec3_clamp(t_vec3 source, t_num min, t_num max);
t_vec3				vec3_max_num(t_vec3 v, t_num n);
t_vec3				vec3_max_min(t_vec3 v, t_num n);

/* ************************************************************************** */
/*                                convert                                     */
/* ************************************************************************** */

t_vec3				vec2to3_xy0(t_vec2 v2);
t_vec3				vec2to3_xxy(t_vec2 v2);
t_vec3				vec2to3_xyy(t_vec2 v2);

t_vec2				vec3to2_xy(t_vec3 v3);
t_vec2				vec3to2_yz(t_vec3 v3);
t_vec2				vec3to2_xz(t_vec3 v3);

#endif
