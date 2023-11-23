/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:22:56 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/27 14:22:58 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[100];
    int	b[1000];
    int i;
    int	counta = 100;
    int	countb = 0;

    srand(time(NULL));

    for (i = 0; i < 100; i++) {
        a[i] = i + 1;
    }

    for (i = 99; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    printf("Array of numbers from 1 to 100 in random order:\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    throwtob(a, b, &counta, &countb);
    throwtoa(a, b, &counta, &countb);
    printf("Array A after swap: ");
    for (int i = 0; i < counta; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Array B after swap: ");
    for (int i = 0; i < countb; ++i)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    printf("counta : %i\n", counta);
    printf("countb : %i\n", countb);
    return 0;
}
*/
