/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:08:58 by jechoo            #+#    #+#             */
/*   Updated: 2023/11/12 23:08:59 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define OVERHEAD 0

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				numofphilos;
	long			starttime;
	long			dietime;
	long			eattime;
	long			sleeptime;
	int				timestoeat;
	int				end_sim;
	int				*philoid;
	int				*state;
	int				*mealseaten;
	long			*lasttimeeaten;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	int				i;
}	t_list;

int		ft_atoi(const char *str);
long	getcurrenttime(void);
int		checkdie(t_list *data);
void	pickupforks(pthread_mutex_t *forks, int id, t_list *data);
void	putdownforks(pthread_mutex_t *forks, int id, t_list *data);
int		checkmeals(t_list *data);
void	update_meals(t_list *data, int *id);
void	printeat(t_list *data, int *id);
void	printsleep(t_list *data, int *id);
void	printthink(int *id);
void	infinite(t_list *data, int *id);
void	join_free(t_list *data, pthread_t *threads);

#endif
