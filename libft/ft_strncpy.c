/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:36:16 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/16 13:36:18 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*dstn;

	dstn = dst;
	while (*src != '\0' && len > 0)
	{
		*dstn++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*dstn++ = '\0';
		len--;
	}
	return (dst);
}
