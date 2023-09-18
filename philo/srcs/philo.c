/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:04:14 by anmande           #+#    #+#             */
/*   Updated: 2023/09/18 17:18:30 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print(int i, char *s, t_phi *phi)
{
	pthread_mutex_lock(&phi->table->lock);
	if (i == 1)
		phi->table->dead++;
	if (phi->table->dead == 1)
	{
		phi->table->dead++;
		printf("%d %d died\n", truetime(phi->table), phi->id);
		pthread_mutex_unlock(&phi->table->lock);
		return ((void)0);
	}
	else if (phi->table->dead == 0)
	{
		printf("%d %d %s\n", truetime(phi->table), phi->id, s);
	}
	pthread_mutex_unlock(&phi->table->lock);
	i++;
}

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
