/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:22:18 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/23 15:22:19 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_kostil_1(char const *s, size_t j)
{
	while ((s[j] == 9 || s[j] == 10 || s[j] == 32) && s[j] != '\0')
		j++;
	return (j);
}

static size_t	ft_kostil_2(char const *s, size_t i, size_t j)
{
	while (s[i + j] != '\0')
		i++;
	i--;
	while ((s[i + j] == 9 || s[i + j] == 10 || s[i + j] == 32) && s[j] != '\0')
		i--;
	i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (s == NULL)
		return (0);
	i = 0;
	j = 0;
	j = ft_kostil_1(s, j);
	i = ft_kostil_2(s, i, j);
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (0);
	k = i;
	i = 0;
	while (k != 0)
	{
		*(str++) = s[i + j];
		i++;
		k--;
	}
	*str = '\0';
	return (str - i);
}
