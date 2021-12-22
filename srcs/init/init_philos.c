/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:37:05 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 16:42:29 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	init_philos(long long num, t_system *philo_system)
{
	philo_system->philos = (t_philo *)malloc(sizeof(t_philo) * num);
	if (!philo_system->philos)
	{
		philo_system->philos = NULL;
		clear_all(philo_system);
		return (-1);
	}
	return (0);
}

int	philo_setting(long long num, t_system *philo_system)
{
	long long	i;
	t_philo		*philo;
	void		*status;

	i = 0;
	if (init_philos(num, philo_system))
		return (-1);
	philo = philo_system->philos;
	while (i < num)
	{
		(philo[i]).last_meal_time = 0;
		(philo[i]).philo_index = i + 1;
		(philo[i]).num_ate = 0;
		(philo[i]).philo_system = philo_system;
		if (pthread_create(&(philo[i].philo_id), NULL, philosophers, &philo[i]))
		{
			philo_system->shared->philo_status = ERROR;
			philo_system->shared->time_status = ERROR;
			while (i-- >= 0)
				pthread_join(philo[i + 1].philo_id, &status);
			return (ft_error(philo_system));
		}
		i++;
	}
	return (0);
}
