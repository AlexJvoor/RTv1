/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:34:18 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/23 16:34:19 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			i++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (i);
}

static char		**ft_freeall(char **str, size_t n)
{
	while (n != 0)
	{
		ft_memdel((void *)str[n]);
		n--;
	}
	ft_memdel((void *)str);
	return (NULL);
}

static	char	*ft_fillstr(char const *s, char c, size_t i)
{
	char	*str;
	size_t	l;

	l = i;
	while (s[l] != c && s[l])
		l++;
	str = ft_strsub(s, (unsigned int)i, (l - i));
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	n;
	size_t	words;
	char	**str;

	i = 0;
	n = 0;
	words = ft_countwords(s, c);
	if (s == NULL || (str = (char **)malloc(sizeof(char *)
		* (words + 1))) == NULL)
		return (NULL);
	while (n != words)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		str[n] = ft_fillstr(s, c, i);
		if (str[n] == NULL)
			return (ft_freeall(str, n));
		i = i + ft_strlen(str[n]);
		n++;
	}
	str[words] = NULL;
	return (str);
}
