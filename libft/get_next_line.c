/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 06:10:05 by jvoor             #+#    #+#             */
/*   Updated: 2019/05/29 09:10:11 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*f_strncat(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (j < n && s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

static char		*ft_strre(char *str, char *buff)
{
	char	*nstr;
	size_t	ls;
	size_t	lb;

	if (str != NULL)
		ls = ft_strlen(str);
	else
		ls = 0;
	if (buff != NULL)
		lb = ft_strlen(buff);
	else
		lb = 0;
	if ((nstr = ft_strnew(ls + lb)) == NULL)
		return (NULL);
	nstr = f_strncat(nstr, str, ls);
	nstr = f_strncat(nstr, buff, lb);
	free(str);
	str = NULL;
	return (nstr);
}

static char		*ft_gnln(char **str)
{
	char	*tostr;
	char	*tobuff;
	char	*s;
	size_t	i;

	i = 0;
	s = *str;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	tostr = ft_strnew(i);
	tostr = ft_strncpy(tostr, s, i);
	tobuff = ft_strnew(ft_strlen(&(s[i + 1])));
	tobuff = ft_strncpy(tobuff, &s[i + 1], ft_strlen(&s[i]));
	free(*str);
	*str = tobuff;
	return (tostr);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[4864];
	char			buff[BUFF_SIZE + 1];
	int				readed;

	if (line == NULL || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	while (!(ft_findchr(str[fd], '\n')))
	{
		readed = read(fd, buff, BUFF_SIZE);
		buff[readed] = '\0';
		if (readed <= 0)
			break ;
		str[fd] = ft_strre(str[fd], buff);
	}
	if (ft_strlen(str[fd]) || readed > 0)
	{
		*line = ft_gnln(&str[fd]);
		return (1);
	}
	if (str[fd])
	{
		free(str[fd]);
		str[fd] = NULL;
	}
	return (0);
}
