/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:22:15 by anmande           #+#    #+#             */
/*   Updated: 2023/07/01 16:50:00 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_parseur(int argc, char **argv)
{
	if (!ft_checkarg(argc, argv))
	{
		printf("Error\n");
		return (0);
	}	
	return (1);
}

int	ft_checkarg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5 || argc > 6)
		return (0);
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}

int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (2048);
}
