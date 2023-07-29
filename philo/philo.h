/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:20:50 by ahamou            #+#    #+#             */
/*   Updated: 2023/06/25 01:37:55 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_main
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	size_t			id_of_philo;
	size_t			debut_time;
	size_t			last_meal;
	size_t			last_sleep;
	size_t			*meals;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	all;
}	t_main;

// functions
size_t	get_time(void);
int		check_death(t_main *philo);
void	set_args(t_main *main, char **av);
void	get_forks(t_main *philo, size_t id);
void	*routine(t_main *philo);
void	ft_sleep(size_t time);
void	w_m(char *str, t_main *p, size_t id);
int		parse_args(char **av);
int		ft_atoi(char *str);

#endif
