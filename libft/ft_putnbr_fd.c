/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:14:21 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/23 15:14:22 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int	i;
	int			sign;

	i = nb;
	sign = 1;
	if (i < 0)
	{
		i = i * -1;
		sign = -1;
	}
	if (sign == -1)
		ft_putchar_fd('-', fd);
	if (i / 10 != 0)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((i % 10) + 48, fd);
}
