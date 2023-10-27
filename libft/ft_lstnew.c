/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:47:49 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/09 14:47:51 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newstruct;

	newstruct = (t_list *)malloc(sizeof(t_list));
	if (!newstruct)
		return (0);
	newstruct->content = content;
	newstruct->next = NULL;
	return (newstruct);
}
