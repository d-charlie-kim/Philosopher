/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:24 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/20 20:55:46 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "struct.h"

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

void	init_philos(long long num, t_system *philo_system)
{
	long long	i;
	t_philo	philo;

	i = 0;
	philo_system->philos = (t_philo *)malloc(sizeof(t_philo) * num);
	if (!philo_system->philos)
		return ;
	while (i < num)
	{
		philo = (philo_system->philos)[i];
		philo.philo_num = i + 1;
		philo.num_ate = 0;
		philo.right_fork = NULL;
		philo.left_fork = NULL;
		// pthread_create(philos[i].philo_id, NULL, (void *)function, philo_sywstem);
		i++;
	}
}

void	init_monitors(long long num, t_system *philo_system)
{
	long long	i;
	t_monitor	*monitor;

	i = 0;
	philo_system->monitors = (t_monitor *)malloc(sizeof(t_monitor) * num);
	if (!philo_system->monitors)
		return ;
	while (i < num)
	{
		monitor = (philo_system->monitors)[i];
		monitor->monitor_num = i + 1;
		monitor->monitoring_philo = (philo_system->philos)[i];
		// pthread_create(philos[i].philo_id, NULL, (void *)function, philo_sywstem);
		i++;
	}
}

void	init_forks(long long num, t_system *philo_system)
{
	long long	i;
	t_fork	*fork;

	i = 0;
	philo_system->forks = (t_fork *)malloc(sizeof(t_fork) * num);
	if (!philo_system->forks)
		return ;
	while (i < num)
	{
		fork = (philo_system->forks)[i];
		fork->index = i + 1;
		// pthread_mutex_init(fork->mutex_fork, NULL);
		// 뮤텍스 생성 에러 처리 해야함
	}
}

void	init_shared(t_system *philos_system)
{
	t_shared	*shared;

	philos_system->shared = (t_shared)malloc(sizeof(t_shared));
	shared = philos_system->shared;
	shared->philo_status = ALIVE;
	// shared->current_time = 0;
	// shared->starting_time = 0;
	// pthread_mutex_init(print_status);
	// 뮤텍스 에러 확인
}