/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:51:34 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/06 12:15:08 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (0);
	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

static void	*ft_reverse_memcpy(void *dest, const void *src, size_t n)

{

	const unsigned char	*s;

	unsigned char		*d;



	s = (const unsigned char *) src;

	d = (unsigned char *) dest;

	while (n--)

		*(d + n) = *(s + n);

	return (dest);

}

void	*ft_memmove(void *dest, const void *src, size_t n)

{

	if (dest == (void *)src || n == 0)

		return (dest);

	if (dest > src && dest - src < (long int) n)

		return (ft_reverse_memcpy(dest, src, n));

	return (ft_memcpy(dest, src, n));

}
#include <stdio.h>
#include <string.h>

int main() {
    char src[50] = "Hello, world!";
    char dest[50];

    // Copy 'src' to 'dest' using your ft_memmove
    ft_memmove(dest, src, strlen(src) + 1);

    // Now try to move the first 7 characters in 'dest' forward by 5 positions
    ft_memmove(dest + 5, dest, 7);

    printf("Result using ft_memmove: %s\n", dest);

    // Reset 'dest'
    strcpy(dest, src);

    // Now try the same thing using the standard memmove
    memmove(dest + 5, dest, 7);

    printf("Result using memmove: %s\n", dest);

    return 0;
}