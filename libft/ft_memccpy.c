/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:07:19 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/15 14:07:21 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*sdst;

	sdst = (char *)dst;
	while (n-- != 0)
	{
		if ((*sdst++ = *((char *)src++)) == (char)c)
			return ((void *)sdst);
	}
	return (0);
}
