/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:45:24 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/15 15:45:26 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[i + j] != '\0')
	{
		while (str1[i + j] == str2[j] && str2[j] != '\0')
			j++;
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
	if (j != 0)
		return ((char *)(str1 + i));
	return (0);
}
