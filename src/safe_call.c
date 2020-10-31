/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:44:44 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/23 13:44:45 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define ERROR			"\033[38;2;200;0;30m"
#define EOC				"\033[38;2;0m"

void	remove_data(t_data *data)
{
	t_list		*tmp;

	ft_memdel((void **)&data->light);
	tmp = data->objs;
	while (data->objs)
	{
		tmp = data->objs->next;
		ft_memdel((void **)&data->objs->content);
		ft_memdel((void **)&data->objs);
		if (tmp)
			data->objs = tmp->next;
	}
}

int		safe_call_int(int res, char *message, t_data *data)
{
	if (res == 0)
		return (res);
	ft_putstr_fd(ERROR, 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd(EOC, 2);
	remove_data(data);
	exit(0);
}

void	*safe_call_ptr(void *res, char *message, t_data *data)
{
	if (res != NULL)
		return (res);
	ft_putstr_fd(ERROR, 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd(EOC, 2);
	remove_data(data);
	exit(0);
}
