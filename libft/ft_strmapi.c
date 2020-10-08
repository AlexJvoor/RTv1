/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:34:01 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/23 16:34:03 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	j;

	j = 0;
	if (s == NULL)
		return (0);
	str = (char *)malloc(sizeof(*f) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (0);
	while (s[j] != '\0')
	{
		str[j] = f(j, (char)s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
