/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:58:30 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/12 13:58:32 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	i;
	int			flag;

	i = 0;
	flag = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	if (flag == 1 && i != i * 10 / 10)
		return (-1);
	if (flag == -1 && i != i * 10 / 10)
		return (0);
	return (i * flag);
}
