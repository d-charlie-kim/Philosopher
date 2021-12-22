/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:24 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 16:40:19 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "error.h"

int	init_info(int argc, char **argv, t_system *philo_system)
{
	t_info	*info;

	philo_system->philo_info = (t_info *)malloc(sizeof(t_info));
	if (!philo_system->philo_info)
	{
		free (philo_system);
		return (-1);
	}
	info = philo_system->philo_info;
	info->philos_num = ft_atoll(argv[1]);
	info->time_to_die = ft_atoll(argv[2]);
	info->time_to_eat = ft_atoll(argv[3]);
	info->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		info->max_eat = ft_atoll(argv[5]);
	else
		info->max_eat = -1;
	return (0);
}

int	init_shared(t_system *philo_system)
{
	t_shared	*shared;

	philo_system->shared = (t_shared *)malloc(sizeof(t_shared));
	if (!philo_system->shared)
	{
		free (philo_system->philo_info);
		free (philo_system);
		return (-1);
	}
	shared = philo_system->shared;
	shared->philo_status = ALIVE;
	shared->elapsed_time = 0;
	shared->all_ate_num = 0;
	shared->starting_time = 0;
	shared->time_status = NOT_START;
	if (pthread_mutex_init(&(shared->print_status), NULL))
		return (-1);
	return (0);
}

int	init_monitor(t_system *philo_system)
{
	if (pthread_create(&(philo_system->monitor_id), \
								NULL, monitor, philo_system))
		return (ft_error(philo_system));
	return (0);
}
