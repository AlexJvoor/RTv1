/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:11:29 by jvoor             #+#    #+#             */
/*   Updated: 2019/04/23 15:11:30 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *content, size_t content_size)
{
	if (content == NULL && content_size == 0)
		return ;
	free(content);
	content = NULL;
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*map;
	t_list		*back;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	map = ft_lstnew(tmp->content, tmp->content_size);
	if (!map)
		return (NULL);
	back = map;
	while ((lst = lst->next))
	{
		tmp = f(lst);
		map->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!(map->next))
		{
			ft_lstdel(&back, ft_del);
			return (0);
		}
		map = map->next;
	}
	return (back);
}
