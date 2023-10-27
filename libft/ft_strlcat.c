/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:42:05 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/06 12:42:15 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	destlen;
	size_t	i;

	if (destsize <= ft_strlen(dest))
		return (destsize + ft_strlen(src));
	destlen = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && destlen + i < destsize - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
