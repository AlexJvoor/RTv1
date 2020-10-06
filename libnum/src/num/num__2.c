/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:27:17 by hush              #+#    #+#             */
/*   Updated: 2020/07/19 14:45:55 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_num		num_min(t_num a, t_num b)
{
	return (a < b ? a : b);
}

t_num		num_max(t_num a, t_num b)
{
	return (a > b ? a : b);
}

t_num		num_clamp(t_num val, t_num min, t_num max)
{
	if (val < min)
	{
		return (min);
	}
	if (val > max)
	{
		return (max);
	}
	return (val);
}

t_num		num_map(t_num x, t_vec2 in, t_vec2 out)
{
    return ((x - in.x) * (out.y - out.x) / (in.y - in.x) + out.x);
}
