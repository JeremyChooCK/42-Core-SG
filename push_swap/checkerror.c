/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:41:19 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/13 13:41:34 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*convertarr(char **av, int ac)
{
	int	i;
	int	j;
	int	*arr;

	i = 1;
	j = 0;
	arr = malloc(sizeof(int) * (ac - 1));
	while (i < ac)
	{
		arr[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	return (arr);
}

static int	*convertarr1(char **av)
{
	int		i;
	int		*arr;
	char	**b;

	b = ft_split(av[1], ' ');
	i = 0;
	arr = malloc(sizeof(int) * ft_strlen(b));
	while (b[i] != NULL)
	{
		arr[i] = ft_atoi(b[i]);
		i++;
	}
	i = 0;
	while (b[i] != NULL)
	{
		free(b[i]);
		i++;
	}
	free(b);
	return (arr);
}

void	checkdupes(int ac, char *av[])
{
	int	*a;
	int	i;
	int	j;

	i = 0;
	if (ac == 2)
		a = convertarr1(av);
	else
		a = convertarr(av, ac);
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (a[i] == a[j])
				printerror();
			j++;
		}
		i++;
	}
	free(a);
}

void	acmorethan2(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[1][j] == ' ')
				j++;
			if (av[i][j] == '-' && (av[i][j + 1] < '0' || av[i][j + 1] > '9'))
				printerror();
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-')
				printerror();
			j++;
		}
		i++;
	}
}

void	checkerror(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] == ' ')
				i++;
			if (av[1][i] == '-' && (av[1][i + 1] < '0' || av[1][i + 1] > '9'))
				printerror();
			if ((av[1][i] < '0' || av[1][i] > '9') && av[1][i] != '-')
				printerror();
			i++;
		}
	}
	acmorethan2(ac, av);
	checkdupes(ac, av);
}
