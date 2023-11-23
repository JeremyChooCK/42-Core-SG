/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:44:26 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/13 12:22:51 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(int *a, int *b, int *counta, int *countb)
{
	int	largestindex;

	largestindex = findlargestindex(a, 5);
	if (largestindex == 0)
		rra(a, *counta);
	if (largestindex == 1)
	{
		rra(a, *counta);
		rra(a, *counta);
	}
	if (largestindex == 2)
	{
		ra(a, *counta);
		ra(a, *counta);
	}
	if (largestindex == 3)
		ra(a, *counta);
	pb(a, b, counta, countb);
	sort4(a, b, counta, countb);
	pa(a, b, counta, countb);
	ra(a, *counta);
}
