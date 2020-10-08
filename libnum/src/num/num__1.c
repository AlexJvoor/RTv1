/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 23:22:27 by hush              #+#    #+#             */
/*   Updated: 2020/07/19 14:45:43 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_num		num_plus(t_num a, t_num b)
{
	return (a + b);
}

t_num		num_minus(t_num a, t_num b)
{
	return (a - b);
}

t_num		num_mult(t_num a, t_num b)
{
	return (a * b);
}

t_num		num_div(t_num a, t_num b)
{
	return (a / b);
}

t_num		num_sqr(t_num a)
{
	return (a * a);
}
