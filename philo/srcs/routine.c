/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:57:32 by admin             #+#    #+#             */
/*   Updated: 2023/09/17 18:10:02 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check(t_phi *phi)
{
	if (truetime(phi->table) >= phi->t2die)
		return (1);
	return (0);
}

void	ft_drop_fork(t_phi *phi)
{
	pthread_mutex_unlock(phi->lf);
	pthread_mutex_unlock(phi->rf);
}

int	ft_take_fork(t_phi *phi)
{
	if (phi->id % 2 == 0)
		pthread_mutex_lock(phi->rf);
	else
		pthread_mutex_lock(phi->lf);
	ft_print(check(phi), "has taken a fork", phi);
	if (phi->id % 2 == 0)
	{
		if (pthread_mutex_lock(phi->lf) != 0)
			return (pthread_mutex_unlock(phi->rf), 1);
		ft_print(check(phi), "has taken a fork", phi);
	}
	else
	{
		if (pthread_mutex_lock(phi->rf) != 0)
			return (pthread_mutex_unlock(phi->lf), 1);
		ft_print(check(phi), "has taken a fork", phi);
	}
	return (0);
}

void	ft_eating(t_phi *phi)
{
	if (phi->table->dead != 0)
		return ;
	ft_take_fork(phi);
	ft_print(check(phi), "is eating", phi);
	ft_usleep(phi->table->time_to_eat, phi);
	ft_drop_fork(phi);
	ft_print(check(phi), "is sleeping", phi);
	ft_usleep(phi->table->time_to_sleep, phi);
	phi->t2die = truetime(phi->table) + phi->table->time_to_die;
}

void	*ft_routine(void *phi_ptr)
{
	t_phi	*phi;

	phi = phi_ptr;
	if (phi->table->nb_philo == 1)
	{
		printf("%d %d has taken a fork\n", 0, phi->id);
		usleep(phi->t2die * 1000);
		printf("%d %d died\n", phi->t2die, phi->id);
		return (NULL);
	}
	// if (phi->id % 2 != 0 && truetime(phi->table) < (unsigned int)10)
	// {
	// 	ft_usleep(100, phi);
	// }
	while (phi->nb_meal != 0 && phi->table->dead == 0)
	{
		phi->nb_meal--;
		ft_eating(phi);
	}
	pthread_mutex_destroy(phi->lf);
	return ((void *)0);
}
