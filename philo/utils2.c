/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:57:27 by ahamou            #+#    #+#             */
/*   Updated: 2023/06/25 01:46:33 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_args(t_main *main, char **av)
{
	int	i;

	i = 0;
	main->n_philos = ft_atoi(av[1]);
	main->time_to_die = ft_atoi(av[2]);
	main->time_to_eat = ft_atoi(av[3]);
	main->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		main->times_must_eat = ft_atoi(av[5]);
	else
		main->times_must_eat = -1;
	main->forks = malloc(sizeof(pthread_mutex_t) * main->n_philos);
	main->meals = malloc(sizeof(size_t) * main->n_philos);
	main->threads = malloc(sizeof(pthread_t) * main->n_philos);
	while (i < main->n_philos)
	{
		pthread_mutex_init(&main->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&main->all, NULL);
	pthread_mutex_init(&main->write, NULL);
	main->debut_time = get_time();
	main->last_meal = 0;
}

void	w_m(char *str, t_main *p, size_t id)
{
	pthread_mutex_lock(&p->write);
	printf(str, get_time() - p->debut_time, id + 1);
	pthread_mutex_unlock(&p->write);
}

void	get_forks(t_main *philo, size_t id)
{
	pthread_mutex_lock(&philo->forks[id]);
	w_m("%lu ms %lu has take a fork\n", philo, id);
	pthread_mutex_lock(&philo->forks[(id + 1) % philo->n_philos]);
	pthread_mutex_lock(&philo->all);
	philo->meals[id] = get_time();
	pthread_mutex_unlock(&philo->all);
	w_m("%lu ms %lu has take a fork\n", philo, id);
	w_m("%lu ms %lu is eating\n", philo, id);
	ft_sleep(philo->time_to_eat);
}

void	*routine(t_main *philo)
{
	size_t	id;

	pthread_mutex_lock(&philo->all);
	id = philo->id_of_philo;
	pthread_mutex_unlock(&philo->all);
	while (1)
	{
		get_forks(philo, id);
		pthread_mutex_unlock(&philo->forks[id]);
		pthread_mutex_unlock(&philo->forks[(id + 1) % philo->n_philos]);
		pthread_mutex_lock(&philo->all);
		philo->last_meal++;
		w_m("%lu ms: %lu is sleeping\n", philo, id);
		pthread_mutex_unlock(&philo->all);
		ft_sleep(philo->time_to_sleep);
		w_m("%lu ms: %lu is thinking\n", philo, id);
	}
}

int	check_death(t_main *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->n_philos)
		{
			pthread_mutex_lock(&philo->all);
			if (philo->times_must_eat != -1 && (size_t)philo->n_philos
				* (size_t)philo->times_must_eat <= philo->last_meal)
				return (1);
			if (get_time() - philo->meals[i] >= (size_t)philo->time_to_die)
			{
				w_m("%lu ms %lu is died\n", philo, i);
				return (1);
			}
			pthread_mutex_unlock(&philo->all);
			i++;
		}
	}
}
