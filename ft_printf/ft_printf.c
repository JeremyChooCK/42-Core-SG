/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:54:38 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/15 19:23:20 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checktype(va_list args, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(args, unsigned long), c));
	else if (c == 'u')
		return (ft_uitoa(va_arg(args, int)));
	else if (c == 'p')
		return (ft_printaddress(va_arg(args, unsigned long)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t		i;
	int			len;
	va_list		args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			len += checktype(args, str[i + 1]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}
/*#include <limits.h>
#include <stdio.h>
int	main()
{
	//int	i = 122;
	int a = printf(" %x \n", LONG_MAX);
	printf("%i\n", a);
	int b = ft_printf(" %x \n", LONG_MAX);
	printf("%i\n", b);
}*/
