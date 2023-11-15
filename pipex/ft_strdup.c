/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:36:52 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/08 11:15:45 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dupe;

	dupe = malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (dupe == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}
