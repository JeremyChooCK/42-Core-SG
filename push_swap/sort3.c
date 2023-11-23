/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:03:39 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/12 20:03:41 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign123(int *a, int *smallest, int *middle, int *largest)
{
	int	i;

	i = 0;
	*smallest = a[0];
	*middle = a[0];
	*largest = a[0];
	while (i < 3)
	{
		if (a[i] < *smallest)
			*smallest = a[i];
		else if (a[i] > *largest)
		{
			if (i == 2)
				*middle = *largest;
			*largest = a[i];
		}
		else
			*middle = a[i];
		i++;
	}
}

void	sort2(int *a, int *counta)
{
	if (a[1] > a[0])
		sa(a, *counta);
}

void	sort3(int *a, int *counta)
{
	int	one;
	int	two;
	int	three;

	assign123(a, &one, &two, &three);
	if (a[0] == one && a[1] == two && a[2] == three)
	{
		sa(a, *counta);
		rra(a, *counta);
	}
	else if (a[0] == one && a[1] == three && a[2] == two)
		rra(a, *counta);
	else if (a[0] == two && a[1] == one && a[2] == three)
		ra(a, *counta);
	else if (a[0] == two && a[1] == three && a[2] == one)
	{
		sa(a, *counta);
		ra(a, *counta);
	}
	else if (a[0] == three && a[1] == one && a[2] == two)
		sa(a, *counta);
	else if (a[0] == three && a[1] == two && a[2] == one)
		return ;
}
