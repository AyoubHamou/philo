/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:54:39 by ahamou            #+#    #+#             */
/*   Updated: 2023/07/29 16:00:33 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(size_t time)
{
	size_t	i;
	size_t	j;

	i = get_time();
	j = (time * 1000) - 5000;
	usleep(j);
	while (get_time() - i < time)
		;
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	get_time(void)
{
	struct timeval	time;
	size_t			t;

	gettimeofday(&time, NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (t);
}

int	ft_atoi(char *str)
{
	unsigned int	result;
	int				i;

	i = 0;
	result = 0;
	if (!str)
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (-1);
		result = result * 10 + str[i] - 48;
		if (result > INT32_MAX)
			return (-1);
		i++;
	}
	return (result);
}

int	parse_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == -1)
		{
			printf("Error : Not a valid args\n");
			return (1);
		}
		i++;
	}
	if (ft_atoi(av[1]) == 0 || !ft_atoi(av[5]))
		return (1);
	return (0);
}
