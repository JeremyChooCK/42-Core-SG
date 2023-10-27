/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:33:13 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/07 11:43:05 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 0;
	end = ft_strlen(s1) - 1;
	while (s1[i] && check(s1[i], set))
		i++;
	while (s1[end] && check(s1[end], set))
		end--;
	if (end == i || i > end)
		result = malloc(sizeof(char));
	else
		result = malloc(sizeof(char) * (end - i) + 2);
	if (!result)
		return (NULL);
	while (i <= end)
		result[j++] = s1[i++];
	result[j] = '\0';
	return (result);
}
/*
#include "libft.h"
#include <stdio.h>

int main()
{
    char const *s1 = "   lorem ipsum dolor sit amet   ";
    char const *set = " l";

    char *trimmed = ft_strtrim(s1, set);

    if (trimmed != NULL)
    {
        printf("Original string: \"%s\"\n", s1);
        printf("%s\n", trimmed);
        free(trimmed); // Don't forget to free the memory allocated by ft_strtrim
    }
    else
    {
        printf("Memory allocation failed!\n");
    }

    return 0;
}*/
