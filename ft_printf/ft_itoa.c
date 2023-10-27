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

#include <unistd.h>
#include <stdlib.h>

static void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

int	countlen(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	checknegative(char *result, long i, int count, long n)
{
	long	len;

	len = countlen(n);
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
		i++;
		count++;
	}
	result[len] = 0;
	len--;
	while (len >= i)
	{
		result[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

int	ft_itoa(int n)
{
	char	*result;
	int		len;
	long	i;
	int		count;
	long	new;

	count = 0;
	new = (long)n;
	i = 0;
	len = countlen(new);
	result = malloc(len + 1);
	if (!result)
		return (0);
	checknegative(result, i, count, new);
	ft_putstr(result);
	free(result);
	return (countlen(new) + count);
}

int	ft_uitoa(int n)
{
	char			*result;
	int				len;
	long			i;
	int				count;
	unsigned long	new;

	count = 0;
	new = (unsigned int)n;
	i = 0;
	len = countlen(new);
	result = malloc(len + 1);
	if (!result)
		return (0);
	checknegative(result, i, count, new);
	ft_putstr(result);
	free(result);
	return (countlen(new) + count);
}
/*
#include <limits.h>
#include <stdio.h>
int    main()
{
//    printf("%i", ft_itoa(-1));
    printf("%i",ft_itoa(-1));
}*/
