/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_call_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:38:05 by hchau             #+#    #+#             */
/*   Updated: 2020/10/21 15:38:07 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define ERROR			"\033[38;2;200;0;30m"
#define EOC				"\033[38;2;0m"

void	remove_parse(t_parse *parse)
{
	if (parse->gnl_str)
		ft_strdel(&parse->gnl_str);
}

int		safe_call_int_parse(int res, char *message,
							t_data *data, t_parse *parse)
{
	if (res == 0)
		return (res);
	remove_parse(parse);
	safe_call_int(-1, message, data);
	exit(0);
}

void	*safe_call_ptr_parse(void *res, char *message,
								t_data *data, t_parse *parse)
{
	if (res != NULL)
		return (res);
	remove_parse(parse);
	safe_call_int(-1, message, data);
	exit(0);
}
