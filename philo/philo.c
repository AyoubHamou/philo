/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:20:43 by ahamou            #+#    #+#             */
/*   Updated: 2023/06/25 01:43:35 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_main		*main;
	int			i;

	i = 0;
	main = malloc(sizeof(t_main) * ft_atoi(av[1]));
	if (ac != 5 && ac != 6)
	{
		printf("not valid args\n");
		return (1);
	}
	if (parse_args(av))
		return (1);
	set_args(main, av);
	i = 0;
	while (i < main->n_philos)
	{
		pthread_mutex_lock(&main->all);
		main->id_of_philo = i;
		main->meals[i] = get_time();
		pthread_mutex_unlock(&main->all);
		pthread_create(&main->threads[i], NULL, (void *)routine, main);
		usleep(100);
		i++;
	}
	return (check_death(main));
}
