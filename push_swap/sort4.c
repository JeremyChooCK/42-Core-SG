/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:59:15 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/12 21:59:34 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findlargestindex(int numbers[], int count)
{
	int	largest;
	int	i;
	int	largestindex;

	largest = numbers[0];
	i = 0;
	largestindex = 0;
	while (i < count)
	{
		if (numbers[i] > largest)
		{
			largest = numbers[i];
			largestindex = i;
		}
		i++;
	}
	return (largestindex);
}

void	sort4(int *a, int *b, int *counta, int *countb)
{
	int	largestindex;

	largestindex = findlargestindex(a, 4);
	if (largestindex == 0)
		rra(a, *counta);
	if (largestindex == 1)
	{
		rra(a, *counta);
		rra(a, *counta);
	}
	if (largestindex == 2)
		ra(a, *counta);
	pb(a, b, counta, countb);
	sort3(a, counta);
	pa(a, b, counta, countb);
	ra(a, *counta);
}
