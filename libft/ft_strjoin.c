/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:39:28 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/07 12:12:05 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin( char const *s1, char const *s2)
{
	size_t	s2len;
	size_t	s1len;
	char	*result;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = malloc((sizeof(char) * (s1len + s2len)) + 1);
	if (result == NULL)
		return (NULL);
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (result - s1len - s2len);
}
/*#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main()
{
    char *s1 = "Hello, ";
    char *s2 = "world!";
    char *joined;

    joined = ft_strjoin(s1, s2);
    if (joined)
    {
        printf("Joined string: %s\n", joined);
        free(joined);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/
