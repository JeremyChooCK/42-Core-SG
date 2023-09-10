/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:58:01 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/08 10:04:58 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*#include <stdio.h>

void my_function(unsigned int index, char *c)
{
	index++;
	index--;
    // Check if the character is lowercase (ASCII value between 'a' and 'z').
    if (*c >= 'a' && *c <= 'z')
    {
        *c = *c - 32;
    }
}

int main()
{
    char my_string[] = "Hello, World!";

    printf("Original string: %s\n", my_string);

    // Apply the modified my_function to capitalize letters in the string.
    ft_striteri(my_string, my_function);

    printf("Modified string: %s\n", my_string);

    return 0;
}*/
