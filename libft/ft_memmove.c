/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:37:31 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/16 11:37:32 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t l)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src)
	{
		i = 0;
		while (i < l)
		{
			((unsigned char*)dst)[i] = ((const unsigned char*)src)[i];
			i++;
		}
	}
	else
	{
		i = l;
		while (i > 0)
		{
			((unsigned char*)dst)[i - 1] = ((const unsigned char*)src)[i - 1];
			i--;
		}
	}
	return (dst);
}
