/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:11:02 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/07 17:20:42 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	deflen(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	reversestring(char str[])
{
	int		length;
	int		start;
	int		end;
	char	temp;

	length = ft_strlen(str);
	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static void	ft_putnbr(int nb, char *result, int i, int len)
{
	int	mod;

	if (nb < 0)
	{
		result[len] = '-';
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, result, i + 1, len);
	}
	mod = (nb % 10) + '0';
	result[i] = mod;
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		nlen;

	nlen = deflen(n);
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = ft_calloc(nlen + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_putnbr(n, result, i, nlen - 1);
	reversestring(result);
	return (result);
}
/*#include<limits.h>
#include <stdio.h>
int    main()
{
    printf("%s", ft_itoa(-2147483));
}*/
