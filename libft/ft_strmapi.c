/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:31:02 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/08 09:45:59 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = ft_strdup(s);
	if (result == NULL)
		return (NULL);
	while (result[i] != '\0')
	{
		result[i] = f(i, result[i]);
		i++;
	}
	return (result);
}
/*#include<stdio.h>
char my_map_function(unsigned int index, char c)
{
	index++;
    if (c >= 'a' && c <= 'z')
        return c - 32; // Convert to uppercase
    else
        return c; // Leave other characters unchanged
}
int main()
{
    const char *input = "Hello, World!";
    char *result = ft_strmapi(input, my_map_function);

    if (result == NULL)
    {
        printf("Memory allocation error.\n");
        return 1;
    }

    printf("Original: %s\n", input);
    printf("Mapped   : %s\n", result);

    free(result); // Remember to free the allocated memory

    return 0;
}*/
