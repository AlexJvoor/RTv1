/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:21:55 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/23 15:22:00 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;

	j = 0;
	if (s == NULL)
		return (0);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (0);
	s = s + start;
	while (j < len && s[j] != '\0')
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
