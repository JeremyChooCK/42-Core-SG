/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:35:09 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/14 17:35:20 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(int *a, int count)
{
	int	i;

	i = 1;
	while (i < count)
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	checksorted(int *a, int counta)
{
	if (issorted(a, counta))
	{
		free(a);
		return (1);
	}
	return (0);
}
