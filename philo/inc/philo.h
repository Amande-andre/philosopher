/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:57:32 by anmande           #+#    #+#             */
/*   Updated: 2023/09/18 16:54:00 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stddef.h>

typedef struct s_phi
{
	int				id;
	int				status;
	unsigned int	birth;
	unsigned int	death;
	unsigned int	t2die;
	unsigned int	t2eat;
	unsigned int	t2sleep;
	int				nb_meal;
	int				eating;
	pthread_t		thread;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
	pthread_mutex_t	lock;
	struct s_data	*table;
}	t_phi;

typedef struct s_data
{
	pthread_t		t0;
	pthread_t		*tid;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				dead;
	int				end;
	unsigned int	start_time;
	struct timeval	tv;
	struct timeval	op;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	t_phi			*phi;
}	t_data;

int				ft_parseur(int argc, char **argv);
int				ft_isdigit(char c);
int				ft_checkarg(int argc, char **argv);
int				ft_philo(t_data *d, int argc, char **argv);
int				ft_setdata(t_data *d, char **argv);
long int		ft_atoi(const char *nptr);
unsigned int	truetime(t_data *d);
void			*ft_routine(void *phi_ptr);
int				ft_init_phi(t_data *d);
int				ft_mutex(t_data *d);
int				init_thread(t_data *d);
void			ft_usleep(unsigned ms, t_phi *phi);
void			ft_clear(t_data *d);
void			*god(void *phi_ptr);
void			ft_print(int i, char *s, t_phi *phi);
int				check(t_phi *phi);

#endif
