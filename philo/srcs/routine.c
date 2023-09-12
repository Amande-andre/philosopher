/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:57:32 by admin             #+#    #+#             */
/*   Updated: 2023/09/12 13:57:24 by anmande          ###   ########.fr       */
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

void	ft_take_fork(t_phi *phi)
{
	pthread_mutex_lock(phi->lf);
	pthread_mutex_lock(phi->rf);
	ft_print(check(phi), "has taken a fork", phi);
	ft_print(check(phi), "has taken a fork", phi);
}

void	ft_eating(t_phi *phi)
{
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
	if (phi->id % 2 != 0 && truetime(phi->table) < (unsigned int)10)
	{
		ft_usleep(100, phi);
	}
	while (phi->nb_meal != 0 && phi->table->dead == 0)
	{
		phi->nb_meal--;
		ft_eating(phi);
	}
	pthread_mutex_destroy(phi->lf);
	return ((void *)0);
}
