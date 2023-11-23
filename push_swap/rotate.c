/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:24:55 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/27 16:24:58 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *a, int count)
{
	int	temp;

	if (count <= 1)
		return ;
	temp = a[count - 1];
	while (--count > 0)
		a[count] = a[count - 1];
	a[0] = temp;
	write(1, "ra\n", 3);
}

void	rb(int *a, int count)
{
	int	temp;

	if (count <= 1)
		return ;
	temp = a[count - 1];
	while (--count > 0)
		a[count] = a[count - 1];
	a[0] = temp;
	write(1, "rb\n", 3);
}

void	rr(int *a, int *b, int counta, int countb)
{
	int	temp;

	if (counta > 1 && countb > 1)
	{
		temp = a[counta - 1];
		while (--counta > 0)
			a[counta] = a[counta - 1];
		a[0] = temp;
		temp = b[countb - 1];
		while (--countb > 0)
			b[countb] = b[countb - 1];
		b[0] = temp;
	}
	write(1, "rr\n", 3);
}
/*
int main() {
    int a[] = {1, 2, 3, 4, 5}; // Example array for testing ra
    int b[] = {6, 7, 8, 9, 10}; // Example array for testing rb
    int counta = 5; // Number of elements in array a
    int countb = 5; // Number of elements in array b

    // Testing ra
    printf("Before ra:\n");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    ra(a, counta);
    printf("After ra:\n");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Testing rb
    printf("Before rb:\n");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    rb(b, countb);
    printf("After rb:\n");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    // Testing rr
    printf("Before rr:\n");
    printf("Array a: ");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\nArray b: ");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    rr(a, b, counta, countb);
    printf("After rr:\n");
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
}
*/
