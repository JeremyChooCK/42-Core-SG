/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:58:38 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/27 16:58:39 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *a, int count)
{
	int	temp;
	int	i;

	i = 0;
	temp = a[0];
	if (count <= 1)
		return ;
	while (i < count - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[count - 1] = temp;
	write(1, "rra\n", 4);
}

void	rrb(int *a, int count)
{
	int	temp;
	int	i;

	i = 0;
	temp = a[0];
	if (count <= 1)
		return ;
	while (i < count - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[count - 1] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(int *a, int *b, int counta, int countb)
{
	int	temp;
	int	i;

	if (counta > 1 && countb > 1)
	{
		i = 0;
		temp = a[0];
		while (i < counta - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		a[counta - 1] = temp;
		i = 0;
		temp = b[0];
		while (i < countb - 1)
		{
			b[i] = b[i + 1];
			i++;
		}
		b[countb - 1] = temp;
	}
	write(1, "rrr\n", 4);
}
/*
int main() {
    int a[] = {1, 2, 3, 4, 5}; // Example array for testing rra
    int b[] = {6, 7, 8, 9, 10}; // Example array for testing rrb
    int counta = 5; // Number of elements in array a
    int countb = 5; // Number of elements in array b

    // Testing rra
    printf("Before rra:\n");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    rra(a, counta);
    printf("After rra:\n");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Testing rrb
    printf("Before rrb:\n");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    rrb(b, countb);
    printf("After rrb:\n");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    // Testing rrr
    printf("Before rrr:\n");
    printf("Array a: ");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\nArray b: ");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    rrr(a, b, counta, countb);
    printf("After rrr:\n");
    printf("Array a: ");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\nArray b: ");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}*/
