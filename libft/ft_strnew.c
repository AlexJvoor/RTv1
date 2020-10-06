/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:04:22 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/18 15:04:24 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (0);
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
