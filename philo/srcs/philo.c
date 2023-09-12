/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:04:14 by anmande           #+#    #+#             */
/*   Updated: 2023/09/12 14:38:07 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print(int i, char *s, t_phi *phi)
{
	if (i == 1)
	{
		phi->table->dead++;
	}
	if (phi->table->dead == 1)
	{
		printf("%d %d died\n", truetime(phi->table), phi->id);
		return ((void)0);
	}
	else if (phi->table->dead == 0)
	{
		printf("%d %d %s\n", truetime(phi->table), phi->id, s);
	}
}

void	*w82d(void *phi_ptr)
{
	t_phi	*phi;

	phi = phi_ptr;
	while (truetime(phi->table) <= (unsigned int)phi->table->time_to_die)
	{
		usleep(10);
	}
	printf("%d %d died\n", truetime(phi->table), phi->id);
	return ((void *)0);
}

void	ft_one_philo(t_data *d)
{
	write(1, "0\n", 2);
	pthread_mutex_init(&d->forks[0], NULL);
	write(1, "1\n", 2);
	pthread_create(&d->tid[0], NULL, &w82d, &d->phi[0]);
	d->phi[0].lf = &d->forks[0];
}

int	ft_philo(t_data *d, int argc, char **argv)
{
	if (!ft_parseur(argc, argv))
		return (0);
	ft_setdata(d, argv);
	if (d->nb_philo == 1)
	{
		ft_one_philo(d);
		ft_clear(d);
		return (1);
	}	
	ft_mutex(d);
	ft_init_phi(d);
	init_thread(d);
	return (1);
}
