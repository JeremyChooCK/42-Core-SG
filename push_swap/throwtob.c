/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throwtob1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:27:10 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/13 13:27:22 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotatedown(int i, int *a, int *counta)
{
	while (checkiandj2(i) == 1)
		rra(a, *counta);
}

int	checktopbtm(int n, int *sortedarr, int count, int totalchunks)
{
	int	chunk;
	int	chunksize;
	int	total;
	int	i;

	i = 0;
	chunk = checkquarter(n, sortedarr, count);
	chunksize = findchunksize(count);
	if (chunk == totalchunks)
		return (0);
	total = (chunk - 1) * chunksize;
	while (n != sortedarr[i])
		i++;
	if (i >= total && i <= total + (chunksize / 2))
		return (0);
	else if (i > total + (chunksize / 2) && i <= total + chunksize)
		return (1);
	return (0);
}

void	throwtob(int *a, int *b, int *counta, int *countb)
{
	int	i;
	int	counter;
	int	*sortedarr;
	int	count;
	int	chunks;

	assignvars(&counter, &count, &chunks, counta);
	sortedarr = assignvars2(a, counta, &i);
	while (i < *counta)
	{
		if (checkquarter(a[i], sortedarr, count) == counter)
		{
			rotatedown(i, a, counta);
			pb(a, b, &(*counta), &(*countb));
			if (checktopbtm(b[*countb - 1], sortedarr, count, chunks) == 1
				&& *countb > 1)
				rb(b, *countb);
			i = -1;
		}
		i++;
		checkcounter(&i, counta, &counter, chunks);
	}
	free(sortedarr);
}
