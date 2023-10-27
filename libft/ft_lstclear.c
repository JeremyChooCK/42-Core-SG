/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:47:01 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/09 16:47:06 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	delone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		l = (*lst)->next;
		delone(*lst, del);
		*lst = l;
	}
}
