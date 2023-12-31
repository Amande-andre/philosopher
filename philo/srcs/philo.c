/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:04:14 by anmande           #+#    #+#             */
/*   Updated: 2023/09/20 18:10:11 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    ft_print(int i, char *s, t_phi *phi)
{
	pthread_mutex_lock(&phi->d->lock);
	if (truetime(phi->d) > phi->t2die)
	{
		printf("%d %d died\n", phi->t2die, phi->id);
		phi->d->dead++;
		pthread_mutex_unlock(&phi->d->lock);
		return ((void)0);
	}
	else if (phi->d->dead == 1)
	{
		phi->d->dead++;
		while (phi->t2die > truetime(phi->d))
		{
			usleep(10);
		}
		printf("%d %d died\n", truetime(phi->d), phi->id);
		pthread_mutex_unlock(&phi->d->lock);
		return ((void)0);
	}
	else if (phi->d->dead == 0)
	{
		printf("%d %d %s\n", truetime(phi->d), phi->id, s);
	}
	pthread_mutex_unlock(&phi->d->lock);
	i++;
}
// void	ft_print(int i, char *s, t_phi *phi)
// {
// 	pthread_mutex_lock(&phi->d->lock);
// 	if (phi->d->dead == 1)
// 	{
// 		phi->d->dead++;
// 		while (phi->t2die > truetime(phi->d))
// 		{
// 			usleep(10);
// 		}
// 		printf("%d %d died\n", truetime(phi->d), phi->id);
// 		pthread_mutex_unlock(&phi->d->lock);
// 		return ((void)0);
// 	}
// 	if (phi->d->dead == 0)
// 	{
// 		printf("%d %d %s\n", truetime(phi->d), phi->id, s);
// 	}
// 	pthread_mutex_unlock(&phi->d->lock);
// 	i++;
// }

int	ft_philo(t_data *d, int argc, char **argv)
{
	if (!ft_parseur(argc, argv))
		return (0);
	ft_setdata(d, argv);
	ft_mutex(d);
	ft_init_phi(d);
	init_thread(d);
	return (1);
}
