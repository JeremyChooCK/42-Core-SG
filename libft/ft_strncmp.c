/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:54:57 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/08 15:38:41 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
    const char *str1 = "test\0";
    const char *str2 = "test\200";
    size_t n = 6; // Number of characters to compare

    // Using your ft_strncmp function
    int result = ft_strncmp(str1, str2, n);
    printf("ft_strncmp result: %d\n", result);

    // Using the standard strncmp function for comparison
    int std_result = strncmp(str1, str2, n);
    printf("Standard strncmp result: %d\n", std_result);

    return 0;
}*/
