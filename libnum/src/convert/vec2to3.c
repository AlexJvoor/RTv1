/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2to3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:34:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/07/19 15:53:47 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec3      vec2to3_xy0(t_vec2 v2)
{
    t_vec3      v3;

    v3.x = v2.x;
    v3.y = v2.y;
    v3.z = 0;
    return (v3);
}

t_vec3      vec2to3_xxy(t_vec2 v2)
{
    t_vec3      v3;

    v3.x = v2.x;
    v3.y = v2.x;
    v3.z = v2.y;
    return (v3);
}

t_vec3      vec2to3_xyy(t_vec2 v2)
{
    t_vec3      v3;

    v3.x = v2.x;
    v3.y = v2.y;
    v3.z = v2.y;
    return (v3);
}