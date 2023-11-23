/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:24:17 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/27 14:24:18 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *arr, int count)
{
	int	temp;

	temp = arr[count - 1];
	arr[count - 1] = arr[count - 1 - 1];
	arr[count - 1 - 1] = temp;
	write(1, "sa\n", 3);
}

void	sb(int *arr, int count)
{
	int	temp;

	temp = arr[count - 1];
	arr[count - 1] = arr[count - 1 - 1];
	arr[count - 1 - 1] = temp;
	write(1, "sb\n", 3);
}

void	ss(int *a, int *b, int counta, int countb)
{
	int	temp;

	temp = a[counta - 1];
	a[counta - 1] = a[counta - 1 - 1];
	a[counta - 1 - 1] = temp;
	temp = b[countb - 1];
	b[countb - 1] = b[countb - 1 - 1];
	b[countb - 1 - 1] = temp;
	write(1, "ss\n", 3);
}
/*
int main() {
    int a[] = {2, 4, 1, 5, 3}; // Example array for testing sa
    int b[] = {7, 10, 6, 8, 9}; // Example array for testing sb
    int counta = 5; // Number of elements in array a
    int countb = 5; // Number of elements in array b

    // Testing sa
    printf("Before sa:\n");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    sa(a, counta);
    printf("After sa:\n");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Testing sb
    printf("Before sb:\n");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    sb(b, countb);
    printf("After sb:\n");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    // Testing ss
    printf("Before ss:\n");
    printf("Array a: ");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\nArray b: ");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    ss(a, b, counta, countb);
    printf("After ss:\n");
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
