/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:13:49 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/26 16:13:53 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

int		ft_strlen(char **str);
int		issorted(int *a, int count);
int		checksorted(int *a, int counta);
void	printerror(void);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	checkerror(int ac, char **av);
void	ra(int *a, int count);
void	rb(int *a, int count);
void	rr(int *a, int *b, int counta, int countb);
void	pa(int *a, int *b, int *counta, int *countb);
void	pb(int *a, int *b, int *counta, int *countb);
void	sa(int *arr, int count);
void	sb(int *arr, int count);
void	ss(int *a, int *b, int counta, int countb);
void	rra(int *a, int count);
void	rrb(int *a, int count);
void	rrr(int *a, int *b, int counta, int countb);
int		findlargestindex(int numbers[], int count);
void	sort2(int *a, int *counta);
void	sort3(int *a, int *counta);
void	sort4(int *a, int *b, int *counta, int *countb);
void	sort5(int *a, int *b, int *counta, int *countb);
void	sortmorethan5(int *a, int *b, int *counta, int *countb);
void	swap(int *a, int *b);
int		partition(int arr[], int low, int high);
void	quicksort(int *arr, int low, int high);
int		*copyandsort(int arr[], int size);
int		checkquarter(int n, int *a, int count);
int		checkiandj(int i);
int		checkiandj2(int i);
int		checktopbtm(int n, int *sortedarr, int count, int totalchunks);
void	assignvars(int *counter, int *count, int *chunks, int *counta);
int		*assignvars2(int *a, int *counta, int *i);
int		findchunksize(int count);
void	pushandswap(int *a, int *b, int *counta, int *countb);
void	checkcounter(int *i, int *counta, int *counter, int chunks);
void	throwtob(int *a, int *b, int *counta, int *countb);
int		findbiggest(int *a, int count);
void	throwtoa(int *a, int *b, int *counta, int *countb);

#endif
