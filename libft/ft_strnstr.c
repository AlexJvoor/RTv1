/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:19:59 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/15 18:20:01 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_costyl(size_t j, size_t i, const char *str1)
{
	if (j != 0)
		return ((char *)(str1 + i));
	return (0);
}

char		*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[i + j] != '\0')
	{
		while (str1[i + j] == str2[j] && str2[j] != '\0')
			j++;
		if (i + j > len)
			return (0);
		if (str2[j] == '\0')
		{
			while (str1[i + j] != '\0')
				j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	return (ft_costyl(j, i, str1));
}
