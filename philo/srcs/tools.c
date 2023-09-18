/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:33:02 by anmande           #+#    #+#             */
/*   Updated: 2023/09/18 15:24:58 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	long long int	n;

	i = 0;
	n = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	return (n * sign);
}

unsigned int	truetime(t_data *d)
{
	unsigned int	time;

	gettimeofday(&d->op, NULL);
	time = (d->op.tv_sec * 1000) + (d->op.tv_usec / 1000);
	return (time - d->start_time);
}

void	ft_usleep(unsigned ms, t_phi *phi)
{
	unsigned int	start;

	start = truetime(phi->table);
	if (phi->t2die <= truetime(phi->table) + ms)
	{
		while (phi->t2die > truetime(phi->table))
			usleep(10);
		pthread_mutex_lock(&phi->table->lock);
		phi->table->dead++;
		pthread_mutex_unlock(&phi->table->lock);
		ft_print(1, "died\n", phi);
		return ;
	}
	while (truetime(phi->table) - start <= ms)
	{
		usleep(10);
	}
}
