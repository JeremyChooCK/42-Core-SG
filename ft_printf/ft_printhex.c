/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 03:11:22 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/16 03:11:24 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n, char c)
{
	char	*hex;
	int		mod;
	int		count;

	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	count = 0;
	if (n > 15)
		count += ft_printhex(n / 16, c);
	mod = n % 16;
	write(1, &hex[mod], 1);
	count++;
	return (count);
}

int	ft_printhexp(unsigned long n)
{
	char	*hex;
	int		mod;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n > 15)
		count += ft_printhexp(n / 16);
	mod = n % 16;
	write(1, &hex[mod], 1);
	count++;
	return (count);
}

int	ft_printaddress(unsigned long n)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (ft_printhexp(n) + 2);
}
/*int	ft_printhexupper(unsigned long n)
{
	char	*hex;
	int		mod;
	int		count;


	hex = "0123456789ABCDEF";
	count = 0;
	if (n > 15)
		count += ft_printhexupper(n / 16);
	mod = n % 16;
	write(1, &hex[mod], 1);
	count++;
	return (count);
}*/
/*
#include<stdio.h>
int main(
{
    int a = 225018;
    int numChars = ft_printhexupper(a);
    printf("\nTotal characters printed: %i\n", numChars);
    return 0;
}*/
