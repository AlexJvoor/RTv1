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

void			change_condition(int kw, t_data *data)
{
	t_list		*tmp;

	tmp = data->objs;
	data->texture_my_sphere = FALSE;
	(*(t_obj **)(tmp->content))->bright_cast = &bright_cast;
	while (tmp)
	{
		if (kw == 18)
			(*(t_obj **)(tmp->content))->bright_cast = &bright_cast;
		else if (kw == 19)
			(*(t_obj **)(tmp->content))->bright_cast = &bright_cast2;
		else if (kw == 20)
			(*(t_obj **)(tmp->content))->bright_cast = &bright_cast3;
		else if (kw == 21)
			data->texture_my_sphere = TRUE;
		tmp = tmp->next;
	}
	update_screen(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}

int				esc_exit(int kw, t_data *data)
{
	if (kw == 53)
	{
		exit(0);
	}
	if (kw == 18 || kw == 19 || kw == 20 || kw == 21)
		change_condition(kw, data);
	return (0);
}

int				main(int ac, char **av)
{
	t_data		data;

	if (ac < 2)
	{
		ft_putendl("\033[38;2;200;0;30mOh my! No arguments in RTv1!\033[38;2;0m");
		return (0);
	}
	init_data(&data);
	parse(av[1], &data);
	update_screen(&data);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.mlx.img, 0, 0);
	mlx_key_hook(data.mlx.win, esc_exit, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
