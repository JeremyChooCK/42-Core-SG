/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:40:49 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/08 15:26:55 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	result = malloc((sizeof(char) * len) + 1);
	if (!result)
		return (NULL);
	while (i < len && s[start] != '\0' && start <= ft_strlen(s))
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
