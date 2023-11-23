/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:25:19 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/27 16:25:22 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(int *a, int *b, int *counta, int *countb)
{
	b[*countb] = a[*counta - 1];
	(*counta)--;
	(*countb)++;
	write(1, "pb\n", 3);
}

void	pa(int *a, int *b, int *counta, int *countb)
{
	a[*counta] = b[*countb - 1];
	(*counta)++;
	(*countb)--;
	write(1, "pa\n", 3);
}
/*
#include <stdio.h>
int main() {
    int a[10] = {1, 2, 3, 4, 5}; // Example array a
    int b[10] = {6, 7, 8, 9, 10}; // Example array b
    int counta = 5; // Number of elements in array a
    int countb = 5; // Number of elements in array b

    // Testing pb
    printf("Before pb:\n");
    printf("Array a: ");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\nArray b: ");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    pb(a, b, &counta, &countb);
    printf("After pb:\n");
    printf("Array a: ");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\nArray b: ");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    // Testing pa
    printf("Before pa:\n");
    printf("Array a: ");
    for (int i = 0; i < counta; i++) {
        printf("%d ", a[i]);
    }
    printf("\nArray b: ");
    for (int i = 0; i < countb; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    pa(a, b, &counta, &countb);
    printf("After pa:\n");
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
