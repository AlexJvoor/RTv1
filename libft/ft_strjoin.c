/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:33:47 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/23 16:33:48 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (s1 == NULL)
		return (0);
	if (s2 == NULL)
		return ((char *)s1);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (0);
	while (*s1 != '\0')
		*str++ = *s1++;
	while (*s2 != '\0')
		*str++ = *s2++;
	*str = '\0';
	return ((char *)(str - len));
}
