/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:33:37 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/06 01:42:24 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			esc_exit(int kw)
{
	if (kw == 53)
	{
		exit(0);
	}
}

t_mlx				init_mlx()
{
	t_mlx		mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "RTv1");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.data = (int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.endn);

	return(mlx);
}

t_cam			init_cam()
{
	t_cam		cam;
	
	cam.pos = vec3(0, 0, 0);
	cam.dir = vec3(1, 0, 0);
	cam.deg = vec3(0, 0, 1);

	return(cam);
}

t_plane			init_plane()
{
	t_plane		plane;
	
	plane.coords = vec3(10, 10, 10);
	plane.norm	= vec3(3, 7, 1);
}

//|vec1| * |vec2| * cos(angl(vec1, vec2)) - скалярное произведение векторов




//нерабочий говнокод следующие 40 строк

int			hit_plane(int *img, t_plane plane, int y, int x)
{
	float t;
	t_vec3		norm_v = vec3_normalize(vec3((t_num)x - 500 , (t_num)y + 500, (t_num)1));//OV
	t_vec3		norm_n = vec3_normalize(plane.norm);//N
	t_vec3		norm_c = vec3_normalize(plane.coords);//OC
	if (vec3_dot(norm_v, norm_n) == 0)
	{
		return (0);
	}
	t = -(vec3_dot(norm_c, norm_n));
	if (t / (vec3_dot(norm_v, norm_n)) <= 0)
	{
		return (0);
	}
	else
	{
		t_vec3 p = vec3_mult_num(norm_v, t);
		img[x + y * WIDTH] = 0xFF0000;
		return(1);
	}
	return (0);
}

void			draw_plane(t_plane plane, int *img)
{
	int			y = 0;
	int			x = 0;

	while (y++ < 1000)
	{
		while (x++ < 1000)
		{
			if (hit_plane(img, plane, y, x) == 1)
			{
				(void)y;
			}	
		}
		x = 0;
	}
}

int				main()
{
	int i = 0;
	t_plane		plane = init_plane();
	t_mlx		mlx = init_mlx();
	t_cam 		cam = init_cam();
	
	while (i++ < 1000000)
	{
		mlx.data[i] = 0xFFFF00;
	}
	draw_plane(plane, mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_key_hook(mlx.win, esc_exit, NULL);
	mlx_loop(mlx.mlx);

    return (0);
}
