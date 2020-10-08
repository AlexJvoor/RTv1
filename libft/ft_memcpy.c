/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:04:37 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/11 18:04:39 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*strdst;
	unsigned char	*strsrc;

	strdst = (unsigned char *)dst;
	strsrc = (unsigned char *)src;
	if (strsrc == NULL && strdst == NULL)
		return (NULL);
	while (n > 0)
	{
		*strdst = *strsrc;
		strdst++;
		strsrc++;
		n--;
	}
	return (dst);
}
