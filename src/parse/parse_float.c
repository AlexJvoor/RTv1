/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:39:12 by hchau             #+#    #+#             */
/*   Updated: 2020/10/21 15:39:14 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char		*get_sign(char *sign, char *str)
{
	*sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r'))
		str++;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	return (str);
}

char		*get_first_num(char *str, t_num *box)
{
	int		i;

	i = 0;
	if (*str < '0' || *str > '9')
		return (NULL);
	while (str[i] && ((str[i] >= '0' && str[i] <= '9')))
		i++;
	if (str[i] != '.' && str[i] != ',')
		return (NULL);
	str[i] = '\0';
	*box = ft_atoi(str);
	str += i + 1;
	return (str);
}

char		*get_second_num(char *str, t_num *box)
{
	int		i;
	char	flag;
	t_num	res;

	i = 0;
	flag = 1;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9')))
		i++;
	if (str[i] == '\0')
		flag = 0;
	else if (str[i] != ',' && str[i] != ' ' && str[i] != '\t')
		return (NULL);
	str[i] = '\0';
	res = ft_atoi(str);
	while (*str)
	{
		res /= 10.0;
		str++;
	}
	*box += *box < 0 ? -res : res;
	str += flag;
	return (str);
}

char		*parse_t_num(char *str, t_num *box)
{
	int		i;
	char	sign;

	i = 0;
	str = get_sign(&sign, str);
	str = get_first_num(str, box);
	if (str == NULL || *str < '0' || *str > '9')
		return (NULL);
	str = get_second_num(str, box);
	if (str == NULL)
		return (NULL);
	*box *= sign;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r'))
		str++;
	return (str);
}
