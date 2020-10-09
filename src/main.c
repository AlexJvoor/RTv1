/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:33:37 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/05 20:26:43 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		change_condition(int kw, t_data *data)
{
	t_list		*tmp;

	tmp = data->objs;
	while (tmp)
	{
		if (kw == 18)
			(*(t_obj **)(tmp->content))->bright_cast = &bright_cast;
		else if (kw == 19)
			(*(t_obj **)(tmp->content))->bright_cast = &bright_cast2;
		else if (kw == 20)
			(*(t_obj **)(tmp->content))->bright_cast = &bright_cast3;
		else if (kw == 21)
			(*(t_obj **)(tmp->content))->bright_cast = &bright_cast4;
		tmp = tmp->next;
	}
	update_screen(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}

int			esc_exit(int kw, t_data *data)
{
	if (kw == 53)
	{
		exit(0);
	}
	if (kw == 18 || kw == 19 || kw == 20 || kw == 21)
		change_condition(kw, data);
	return (0);
}

//t_cam			init_cam()
//{
//	t_cam		cam;
//
//	cam.pos = vec3(0, 0, 0);
//	cam.dir = vec3(1, 0, 0);
//	cam.deg = vec3(0, 0, 1);
//
//	return(cam);
//}

//t_plane			*init_plane()
//{
//	t_plane		*plane;
//
//	plane = ft_memalloc(sizeof(t_plane));
//	plane->norm = vec3_normalize(vec3(0, 0, 12000));
//	plane->dist = 500000.0;
//	return (plane);
//}

int				main()
{
//	int i = 0;
//	t_plane		*plane = init_plane();
//	t_cam 		cam = init_cam();
	t_data		data;

	init_data(&data);
	parse("maps/1", &data);
//	init_plane();

//	t_list *lst_pln = ft_lstnew((&plane), sizeof(t_plane *));
//	ft_lstadd(&data.objs, ft_lstnew((&plane), sizeof(t_plane *)));
//	data.objs->next = ft_lstnew((&plane), sizeof(t_plane *));
	update_screen(&data);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.mlx.img, 0, 0);
	mlx_key_hook(data.mlx.win, esc_exit, &data);
	mlx_loop(data.mlx.mlx);
    return (0);
}
