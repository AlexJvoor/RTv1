/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 23:56:51 by jvoor             #+#    #+#             */
/*   Updated: 2019/05/16 23:56:55 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		arr_compare(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			s2++;
		if (*s1 == '\0')
			i = 1;
	}
	return (i);
}

void			ft_wdmatch(char *s1, char *s2)
{
	if ((arr_compare(s1, s2)) == 1)
		ft_putstr(s1);
}
