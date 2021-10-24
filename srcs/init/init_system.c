/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:44:26 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/24 15:12:57 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_info(int argc, char **argv, t_system *philo_system)
{
	t_info	*info;

	philo_system->philo_info = (t_info *)malloc(sizeof(t_info));
	if (philo_system->philo_info == NULL)
		return ;
	info = philo_system->philo_info;
	info->philos_num = ft_atoll(argv[1]);
	info->time_to_die = ft_atoll(argv[2]);
	info->time_to_eat = ft_atoll(argv[3]);
	info->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		info->max_eat = ft_atoll(argv[5]);
	else
		info->max_eat = -1;
}

#include <stdio.h>

t_system	*init_system(int argc, char **argv)
{
	t_system	*system;

	system = (t_system *)malloc(sizeof(t_system));
	if (!system)
		return (NULL);
	init_info(argc, argv, system);
	if (!system->philo_info)
		return (NULL);
	init_philos(system->philo_info->philos_num, system);
	init_monitors(system->philo_info->philos_num, system);
	init_forks(system->philo_info->philos_num, system);
	init_shared(system);
	if (!system->philos || !system->philo_info || !system->shared \
		|| !system->forks || !system-> monitors)
		return (NULL);
	return (system);
}
