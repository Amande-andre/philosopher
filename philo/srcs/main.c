/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:01:02 by anmande           #+#    #+#             */
/*   Updated: 2023/09/14 11:28:12 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_clear(t_data *d)
{
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
		return (0);
	if (!ft_philo(d, argc, argv))
	{
		return (0);
	}
	ft_clear(d);
	return (0);
}
