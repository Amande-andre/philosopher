/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:01:02 by anmande           #+#    #+#             */
/*   Updated: 2023/09/18 15:15:31 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_clear(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_philo)
	{
		pthread_mutex_destroy(&d->forks[i]);
		i++;
	}
	free(d->forks);
	free(d->tid);
	free(d->phi);
	free(d);
}

int	main(int argc, char **argv)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (1);
	if (!ft_philo(d, argc, argv))
	{
		free(d);
		return (1);
	}
	ft_clear(d);
	return (0);
}
