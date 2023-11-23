/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:10:55 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/26 11:10:57 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convertarr(char **av, int ac, int *count)
{
	int	i;
	int	j;
	int	*arr;

	i = 1;
	j = 0;
	arr = malloc(sizeof(int) * (ac - 1));
	while (i < ac)
	{
		arr[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	*count = j;
	return (arr);
}

int	*convertarr1(char **av, int *count)
{
	int		i;
	int		*arr;
	char	**b;

	b = ft_split(av[1], ' ');
	i = 0;
	arr = malloc(sizeof(int) * ft_strlen(b));
	while (b[i] != NULL)
	{
		arr[i] = ft_atoi(b[i]);
		i++;
	}
	*count = i;
	i = 0;
	while (b[i] != NULL)
	{
		free(b[i]);
		i++;
	}
	free(b);
	return (arr);
}

int	*reversearr(int	*a, int count)
{
	int	*temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(int) * count);
	if (temp == NULL)
		return (NULL);
	count--;
	while (count >= 0)
	{
		temp[count] = a[i];
		count--;
		i++;
	}
	free(a);
	return (temp);
}

int	*convert(int ac, char **av, int *counta)
{
	int	*a;

	if (ac == 2)
		a = convertarr1(av, counta);
	else
		a = convertarr(av, ac, counta);
	return (a);
}

int	main(int ac, char **av)
{
	int	*a;
	int	b[10000];
	int	counta;
	int	countb;

	checkerror(ac, av);
	counta = 0;
	countb = 0;
	a = convert(ac, av, &counta);
	if (checksorted(a, counta) == 1)
		return (0);
	a = reversearr(a, counta);
	if (counta == 2)
		sort2(a, &counta);
	else if (counta == 3)
		sort3(a, &counta);
	else if (counta == 4)
		sort4(a, b, &counta, &countb);
	else if (counta == 5)
		sort5(a, b, &counta, &countb);
	else
		sortmorethan5(a, b, &counta, &countb);
	free(a);
	return (0);
}
