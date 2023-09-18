/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:57:32 by admin             #+#    #+#             */
/*   Updated: 2023/09/18 20:16:53 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check(t_phi *phi)
{
	if (truetime(phi->d) >= phi->t2die)
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

void	ft_time_to_die(t_phi *phi)
{
	pthread_mutex_lock(&phi->d->lock);
	if (truetime(phi->d) + phi->t2eat >= phi->t2die)
	{
		phi->d->dead++;
		pthread_mutex_unlock(&phi->d->lock);
		ft_print(1, "died", phi);
		return ;
	}
	pthread_mutex_unlock(&phi->d->lock);
}

void	ft_eating(t_phi *phi)
{
	//pthread_mutex_lock(&phi->d->lock);
	// if (phi->d->dead != 0)
	// {
	// 	pthread_mutex_unlock(&phi->d->lock);
	// 	return ;
	// }
	//pthread_mutex_unlock(&phi->d->lock);
	ft_take_fork(phi);
	phi->t2die = truetime(phi->d) + phi->d->time_to_die;
	ft_print(check(phi), "is eating", phi);
	ft_usleep(phi->d->time_to_eat, phi);
	ft_drop_fork(phi);
	ft_print(check(phi), "is sleeping", phi);
	ft_usleep(phi->d->time_to_sleep, phi);
	ft_print(check(phi), "is thinking", phi);
	ft_time_to_die(phi);						//place au mauvais endroit, il
}												//a deja dormi. A la limite le mettre 				
//ft_left_before_die(phi);						//avant le ft_usleep de sleeping

void	*ft_routine(void *phi_ptr)
{
	t_phi	*phi;

	phi = phi_ptr;
	if (phi->d->nb_philo == 1)
	{
		printf("%d %d has taken a fork\n", 0, phi->id);
		usleep(phi->t2die * 1000);
		printf("%d %d died\n", phi->t2die, phi->id);
		return (NULL);
	}
	if (phi->id % 2 == 0)
		usleep(100);
	while (phi->nb_meal != 0)
	{
		pthread_mutex_lock(&phi->d->lock);
		if (phi->d->dead == 0)
		{
			phi->nb_meal--;
			pthread_mutex_unlock(&phi->d->lock);
			ft_eating(phi);
		}
		else
		{
			pthread_mutex_unlock(&phi->d->lock);
			return ((void *)0);
		}
	}
	return ((void *)0);
}
