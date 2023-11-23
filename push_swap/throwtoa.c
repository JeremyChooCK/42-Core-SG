/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throwtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:25:55 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/13 13:26:11 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findbiggest(int *a, int count)
{
	int	i;
	int	num;

	i = 0;
	num = -2147483648;
	while (i < count)
	{
		if (a[i] > num)
			num = a[i];
		i++;
	}
	return (num);
}

int	find_biggest_index(int *b, int countb)
{
	int	max_index;
	int	max_value;
	int	i;

	i = 1;
	max_index = 0;
	max_value = b[0];
	while (i < countb)
	{
		if (b[i] > max_value)
		{
			max_value = b[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

void	push_biggest_to_a(int *a, int *b, int *counta, int *countb)
{
	int	max_index;

	max_index = find_biggest_index(b, *countb);
	if (max_index <= *countb / 2)
	{
		while (max_index-- >= 0)
			rrb(b, *countb);
	}
	else
	{
		while (max_index++ < *countb - 1)
			rb(b, *countb);
	}
	pa(a, b, &(*counta), &(*countb));
}

void	throwtoa(int *a, int *b, int *counta, int *countb)
{
	int	i;

	i = 0;
	while (i < *countb)
	{
		if (b[i] == b[find_biggest_index(b, *countb)])
		{
			push_biggest_to_a(a, b, counta, countb);
			i = -1;
		}
		i++;
	}
}
