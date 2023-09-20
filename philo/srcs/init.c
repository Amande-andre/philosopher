/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:22:55 by anmande           #+#    #+#             */
/*   Updated: 2023/09/20 17:34:08 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_thread(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_philo)
	{
		if (pthread_create(&d->tid[i], NULL, &ft_routine, &d->phi[i]) == -1)
			return (1);
		i++;
	}
	i = 0;
	while (i < d->nb_philo)
	{
		if (pthread_join(d->tid[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_phi(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < d->nb_philo)
	{
		d->phi[i].id = j;
		d->phi[i].status = 0;
		d->phi[i].t2die = d->time_to_die;
		d->phi[i].t2sleep = d->time_to_sleep;
		d->phi[i].nb_meal = d->nb_eat;
		d->phi[i].t2eat = d->time_to_eat;
		d->phi[i].last_meal = 0;
		pthread_mutex_init(&d->phi[i].lock, NULL);
		d->phi[i].d = d;
		i++;
		j++;
	}
	return (0);
}

int	ft_setdata(t_data *d, char **argv)
{	
	d->nb_philo = ft_atoi(argv[1]);
	d->time_to_die = (unsigned) ft_atoi(argv[2]);
	d->time_to_eat = (unsigned) ft_atoi(argv[3]);
	d->time_to_sleep = (unsigned) ft_atoi(argv[4]);
	if (argv[5])
		d->nb_eat = ft_atoi(argv[5]);
	else
		d->nb_eat = -1;
	if (d->nb_philo <= 0 || d->nb_philo > 200)
		return (0);
	gettimeofday(&d->tv, NULL);
	d->start_time = (d->tv.tv_sec * 1000) + (d->tv.tv_usec / 1000);
	d->dead = 0;
	pthread_mutex_init(&d->lock, NULL);
	pthread_mutex_init(&d->write, NULL);

	return (0);
}

int	ft_mutex(t_data *d)
{
	int	i;

	i = 0;
	d->tid = malloc(sizeof(pthread_t) * d->nb_philo);
	d->forks = malloc(sizeof(pthread_mutex_t) * d->nb_philo);
	d->phi = malloc(sizeof(t_phi) * d->nb_philo);
	if (!d->tid || !d->forks || !d->phi)
		return (1);
	while (i < d->nb_philo)
	{
		pthread_mutex_init(&d->forks[i], NULL);
		(void)d->forks[i];
		i++;
	}
	i = 1;
	d->phi[0].lf = &d->forks[0];
	d->phi[0].rf = &d->forks[d->nb_philo - 1];
	while (i < d->nb_philo)
	{
		d->phi[i].lf = &d->forks[i];
		d->phi[i].rf = &d->forks[i - 1];
		i++;
	}
	return (0);
}
