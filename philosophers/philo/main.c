/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:07:22 by jechoo            #+#    #+#             */
/*   Updated: 2023/11/12 23:07:24 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_list	*data;
	int		id;

	data = (t_list *)arg;
	pthread_mutex_lock(&data->mutex);
	id = data->i;
	(data->i)++;
	pthread_mutex_unlock(&data->mutex);
	infinite(data, &id);
	return (NULL);
}

void	var_init_part2(t_list *data)
{
	data->philoid = malloc(sizeof(int) * data->numofphilos);
	data->state = malloc(sizeof(int) * data->numofphilos);
	data->mealseaten = malloc(sizeof(int) * data->numofphilos);
	data->lasttimeeaten = malloc(sizeof(long) * data->numofphilos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->numofphilos);
}

void	var_init_part1(t_list *data, char **av, int ac)
{
	data->end_sim = 0;
	data->numofphilos = ft_atoi(av[1]);
	data->dietime = ft_atoi(av[2]);
	data->eattime = ft_atoi(av[3]);
	data->sleeptime = ft_atoi(av[4]);
	data->starttime = getcurrenttime();
	if (ac == 6)
		data->timestoeat = ft_atoi(av[5]);
	else
		data->timestoeat = -1;
}

void	threads_init(t_list *data, pthread_t *threads)
{
	int		i;

	i = 0;
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->numofphilos)
	{
		data->philoid[i] = i;
		data->state[i] = THINKING;
		data->mealseaten[i] = 0;
		data->lasttimeeaten[i] = data->starttime;
		pthread_mutex_init(&(data->forks[i]), NULL);
		pthread_create(&threads[i], NULL, &routine, (void *)data);
		i++;
	}
}

int	main(int ac, char **av)
{
	pthread_t	*threads;
	t_list		*data;

	if (ac == 5 || ac == 6)
	{
		data = malloc(sizeof(t_list));
		var_init_part1(data, av, ac);
		if (data->numofphilos == 0 || data->numofphilos == 1)
		{
			if (data->numofphilos == 1)
				printf("%ld 1 died", getcurrenttime() + data->dietime);
			free(data);
			return (0);
		}
		threads = malloc(sizeof(pthread_t) * data->numofphilos);
		var_init_part2(data);
		threads_init(data, threads);
		while (!data->end_sim)
			checkdie(data);
		join_free(data, threads);
	}
}
