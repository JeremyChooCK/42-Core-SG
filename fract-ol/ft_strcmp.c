/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:16:30 by jechoo            #+#    #+#             */
/*   Updated: 2023/08/02 14:26:33 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0')
		return (-s2[i]);
	return (0);
}

/*#include <stdio.h>
int main()
{
    char str1[] = "Gello";
    char str2[] = "xedloewq";

    int result = ft_strcmp(str1, str2);
    if (result == 0)
    {
        printf("The strings are equal.\n");
    }
    else if (result < 0)
    {
        printf("String 1 is less than String 2.\n");
    }
    else
    {
        printf("String 1 is greater than String 2.\n");
    }

    char str3[] = "Hello";
    char str4[] = "World";

    result = ft_strcmp(str3, str4);
    if (result == 0)
    {
        printf("The strings are equal.\n");
    }
    else if (result < 0)
    {
        printf("String 3 is less than String 4.\n");
    }
    else
    {
        printf("String 3 is greater than String 4.\n");
    }
    printf("%i", ft_strcmp(str3, str4));
    return 0;
}*/
