/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:52:06 by jechoo            #+#    #+#             */
/*   Updated: 2023/11/14 20:52:23 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_free(t_list *data, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->numofphilos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->numofphilos)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&data->mutex);
	free(threads);
	free(data->philoid);
	free(data->state);
	free(data->mealseaten);
	free(data->lasttimeeaten);
	free(data->forks);
	free(data);
}
