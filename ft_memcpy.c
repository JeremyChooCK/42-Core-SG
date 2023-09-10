/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:36:33 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/06 11:49:43 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

​

#include "libft.h"

​

void	*ft_memcpy(void *dest, const void *src, size_t n)

{

	const unsigned char	*s;

	unsigned char		*d;

​

	if (dest == src || !n)

		return (dest);

	s = (const unsigned char *) src;

	d = (unsigned char *) dest;

	while (n--)

		*d++ = *s++;

	return (dest);

}
