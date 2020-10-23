/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:44:06 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/23 13:44:07 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		update_screen(t_data *data)
{
	int		x;
	int		y;

	y = -H_HEIGHT;
	while (y < H_HEIGHT)
	{
		x = -H_WIDTH;
		while (x < H_WIDTH)
		{
			draw_figure(x, y, data);
			x++;
		}
		y++;
	}
}
