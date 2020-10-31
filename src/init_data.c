/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:42:20 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/23 13:42:23 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mlx				init_mlx(void)
{
	t_mlx			mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "RTv1");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.data = (int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.endn);
	return (mlx);
}

void				init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->mlx = init_mlx();
	data->find_destination[SPHERE] = &sphere_cast;
	data->find_destination[PLANE] = &plane_cast;
	data->find_destination[CONE] = &cone_cast;
	data->find_destination[CYLINDER] = &cylinder_cast;
	load_text(data);
}
