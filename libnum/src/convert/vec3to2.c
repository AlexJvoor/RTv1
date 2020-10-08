/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3to2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:34:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/07/19 15:56:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

t_vec2      vec3to2_xy(t_vec3 v3)
{
    t_vec2      v2;

    v2.x = v3.x;
    v2.y = v3.y;
    return (v2);
}

t_vec2      vec3to2_yz(t_vec3 v3)
{
    t_vec2      v2;

    v2.x = v3.y;
    v2.y = v3.z;
    return (v2);
}

t_vec2      vec3to2_xz(t_vec3 v3)
{
    t_vec2      v2;

    v2.x = v3.x;
    v2.y = v3.z;
    return (v2);
}