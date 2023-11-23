/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throwtob_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:30:08 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/13 13:30:26 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkiandj2(int i)
{
	static int	k;

	if (k <= i)
	{
		k++;
		return (1);
	}
	if (k == i + 1)
		k = 0;
	return (0);
}

void	pushandswap(int *a, int *b, int *counta, int *countb)
{
	if (*counta > 1)
	{
		if (a[*counta - 1] > a[*counta - 2] && *countb > 1)
		{
			if (b[*countb - 1] < b[*countb - 2])
				ss(a, b, *counta, *countb);
		}
	}
	if (*countb > 1)
	{
		if (b[*countb - 1] < b[*countb - 2])
			sb(b, *countb);
	}
}

void	checkcounter(int *i, int *counta, int *counter, int chunks)
{
	if (*i == *counta && *counter < chunks)
	{
		*i = 0;
		(*counter)++;
	}
}

void	assignvars(int *counter, int *count, int *chunks, int *counta)
{
	*counter = 1;
	*count = *counta;
	*chunks = *count / findchunksize(*count);
	if (*count % findchunksize(*count) != 0)
		(*chunks)++;
}

int	*assignvars2(int *a, int *counta, int *i)
{
	int	*sortedarr;

	sortedarr = copyandsort(a, *counta);
	*i = 0;
	return (sortedarr);
}
