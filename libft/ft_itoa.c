/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:09:43 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/23 15:09:46 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countsize(long int i)
{
	int	j;

	j = 0;
	if (i == -2147483648)
		return (11);
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i = -i;
		j++;
	}
	while (i != 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

static char	*ft_fillstr(char *str, long int i)
{
	size_t		j;

	if (i == 0)
	{
		*str = '0';
		return (str);
	}
	j = ft_countsize(i);
	str = str + j - 1;
	i = i > 0 ? i : -i;
	while (i)
	{
		*str = i % 10 + '0';
		str--;
		i /= 10;
	}
	str++;
	return (str);
}

char		*ft_itoa(int i)
{
	char		*temp;
	char		*str;
	int			sign;
	long int	in;

	in = i;
	sign = 1;
	str = ft_strnew(ft_countsize(in));
	temp = str;
	if (str == NULL)
		return (NULL);
	if (in < 0)
		sign = -1;
	str = ft_fillstr(str, in);
	if (sign < 0)
	{
		str--;
		*str = '-';
	}
	return (temp);
}
