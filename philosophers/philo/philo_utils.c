/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:42:30 by jechoo            #+#    #+#             */
/*   Updated: 2023/11/14 20:42:43 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	getcurrenttime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	checkdie(t_list *data)
{
	int		i;
	long	timesincelasteaten;

	while (data->end_sim == 0)
	{
		i = 0;
		while (i < data->numofphilos)
		{
			timesincelasteaten = getcurrenttime() - data->lasttimeeaten[i];
			if (timesincelasteaten > data->dietime)
			{
				printf("%ld %d died\n", getcurrenttime(), i + 1);
				pthread_mutex_lock(&data->mutex);
				data->end_sim = 1;
				pthread_mutex_unlock(&data->mutex);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

void	pickupforks(pthread_mutex_t *forks, int id, t_list *data)
{
	int	leftfork;
	int	rightfork;

	leftfork = id;
	if (id == data->numofphilos - 1)
		rightfork = 0;
	else
		rightfork = id + 1;
	if (id == 0)
	{
		pthread_mutex_lock(&forks[rightfork]);
		pthread_mutex_lock(&forks[leftfork]);
	}
	else
	{
		pthread_mutex_lock(&forks[leftfork]);
		pthread_mutex_lock(&forks[rightfork]);
	}
}

void	putdownforks(pthread_mutex_t *forks, int id, t_list *data)
{
	int	leftfork;
	int	rightfork;

	leftfork = id;
	if (id == data->numofphilos - 1)
		rightfork = 0;
	else
		rightfork = id + 1;
	if (id == data->numofphilos - 1)
	{
		pthread_mutex_unlock(&forks[rightfork]);
		pthread_mutex_unlock(&forks[leftfork]);
	}
	else
	{
		pthread_mutex_unlock(&forks[leftfork]);
		pthread_mutex_unlock(&forks[rightfork]);
	}
}

int	checkmeals(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->numofphilos)
	{
		if (data->mealseaten[i] < data->timestoeat || data->timestoeat == -1)
			return (0);
		i++;
	}
	data->end_sim = 1;
	return (1);
}
