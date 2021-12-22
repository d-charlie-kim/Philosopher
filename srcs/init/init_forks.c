/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:39:53 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 16:48:46 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	init_forks(long long num, t_system *philo_system)
{
	philo_system->forks = (t_fork *)malloc(sizeof(t_fork) * num);
	if (!philo_system->forks)
	{
		pthread_mutex_destroy(&(philo_system->shared->print_status));
		free (philo_system->philo_info);
		free (philo_system->shared);
		free (philo_system);
		return (-1);
	}
	return (0);
}

int	fork_setting(long long num, t_system *philo_system)
{
	long long	i;
	t_fork		*fork;

	i = 0;
	if (init_forks(num, philo_system))
		return (-1);
	fork = philo_system->forks;
	while (i < num)
	{
		fork->fork_status = FREE;
		if (pthread_mutex_init(&((fork[i]).fork_mutex), NULL))
		{
			while (i-- >= 0)
				pthread_mutex_destroy(&((fork[i + 1]).fork_mutex));
			free (philo_system->forks);
			pthread_mutex_destroy(&(philo_system->shared->print_status));
			free (philo_system->philo_info);
			free (philo_system->shared);
			free (philo_system);
			return (-1);
		}
		i++;
	}
	return (0);
}
