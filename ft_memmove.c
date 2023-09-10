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

#include "libft.h"

static void	*ft_reverse_memcpy(void *dest, const void *src, size_t n)

{

	const unsigned char	*s;

	unsigned char		*d;

​

	s = (const unsigned char *) src;

	d = (unsigned char *) dest;

	while (n--)

		*(d + n) = *(s + n);

	return (dest);

}

​

void	*ft_memmove(void *dest, const void *src, size_t n)

{

	if (dest == (void *)src || n == 0)

		return (dest);

	if (dest > src && dest - src < (long int) n)

		return (ft_reverse_memcpy(dest, src, n));

	return (ft_memcpy(dest, src, n));

}
