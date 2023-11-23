/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throwtob_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:29:03 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/13 13:29:18 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copyandsort(int arr[], int size)
{
	int		i;
	int		*copiedarray;

	i = 0;
	copiedarray = malloc(size * sizeof(int));
	while (i < size)
	{
		copiedarray[i] = arr[i];
		i++;
	}
	quicksort(copiedarray, 0, size - 1);
	return (copiedarray);
}

int	findchunksize(int count)
{
	if (count >= 500)
		return (65);
	if (count >= 400)
		return (28);
	if (count >= 300)
		return (23);
	if (count >= 200)
		return (18);
	if (count >= 100)
		return (19);
	return (5);
}

int	findnum(int *a, int count, int n)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (a[i] == n)
			break ;
		i++;
	}
	return (i);
}

int	checkquarter(int n, int *a, int count)
{
	int	i;
	int	temp;
	int	temp2;
	int	result;
	int	chunksize;

	i = findnum(a, count, n);
	chunksize = findchunksize(count);
	temp = count / chunksize;
	temp2 = temp;
	result = 0;
	while (temp2 > 0)
	{
		if (i + 1 > (temp2 * chunksize))
			return (temp2 + 1);
		else if (i + 1 <= count / temp)
			return (1);
		temp2--;
		result++;
	}
	return (0);
}

int	checkiandj(int i)
{
	static int	j;

	if (j < i)
	{
		j++;
		return (1);
	}
	return (0);
}
