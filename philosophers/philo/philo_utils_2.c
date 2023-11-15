/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:44:57 by jechoo            #+#    #+#             */
/*   Updated: 2023/11/14 20:45:08 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_meals(t_list *data, int *id)
{
	pthread_mutex_lock(&data->mutex);
	data->lasttimeeaten[*id] = getcurrenttime();
	data->mealseaten[*id]++;
	pthread_mutex_unlock(&data->mutex);
}

void	printeat(t_list *data, int *id)
{
	printf("%ld %d is eating\n", data->lasttimeeaten[*id], *id + 1);
	usleep((data->eattime - OVERHEAD) * 1000);
	putdownforks(data->forks, *id, data);
}

void	printsleep(t_list *data, int *id)
{
	printf("%ld %d is sleeping\n", getcurrenttime(), *id + 1);
	usleep((data->sleeptime - OVERHEAD) * 1000);
}

void	printthink(int *id)
{
	printf("%ld %d is thinking\n", getcurrenttime(), *id + 1);
	usleep(1000);
}

void	infinite(t_list *data, int *id)
{
	while (data->end_sim == 0 && checkmeals(data) == 0)
	{
		pickupforks(data->forks, *id, data);
		if (data->end_sim == 1)
		{
			putdownforks(data->forks, *id, data);
			break ;
		}
		update_meals(data, id);
		if (data->end_sim == 1)
			break ;
		printeat(data, id);
		if (data->end_sim == 1)
			break ;
		printsleep(data, id);
		if (data->end_sim == 1)
			break ;
		printthink(id);
	}
}
