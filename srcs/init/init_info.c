/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:24 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/27 21:13:34 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#define ALIVE 3;

void	init_philos(long long num, t_system *philo_system)
{
	long long	i;
	t_philo		*philo;

	i = 0;
	philo_system->philos = (t_philo *)malloc(sizeof(t_philo) * num);
	if (!philo_system->philos)
		return ;
	philo = philo_system->philos;
	while (i < num)
	{
		(philo[i]).philo_index = i + 1;
		(philo[i]).num_ate = 0;
		(philo[i]).philo_system = philo_system;
		setting_philo(&(philo[i]), philo_system);
		// pthread_create(philo[i].philo_id, NULL, philosophers, &(philo[i]));
		// 쓰레드 생성때 에러 처리
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
	monitor = philo_system->monitors;
	while (i < num)
	{
		(monitor[i]).monitor_num = i + 1;
		(monitor[i]).monitoring_philo = &((philo_system->philos)[i]);
		(monitor[i]).philo_system = philo_system;
		// pthread_create(monitor[i].monitor_id, NULL, monitors, &(monitor[i]));
		// 쓰레드 생성때 에러 처리
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
	fork = philo_system->forks;
	while (i < num)
	{
		(fork[i]).fork_index = i + 1;
		pthread_mutex_init(&((fork[i]).mutex_id), NULL);
		// 뮤텍스 생성 에러 처리 해야함
		i++;
	}
}

void	init_shared(t_system *philos_system)
{
	t_shared	*shared;

	philos_system->shared = (t_shared *)malloc(sizeof(t_shared));
	if (!philos_system->shared)
		return ;
	shared = philos_system->shared;
	shared->philo_status = ALIVE;
	pthread_mutex_init(&(shared->print_status), NULL);
	// 뮤텍스 에러 확인
}

void	init_time(t_system *philos_system)
{
	t_time	*time;

	philos_system->time = (t_time *)malloc(sizeof(t_time));
	time = philos_system->time;
	time->current_time = 0;
	time->starting_time = 0;
	pthread_mutex_init(&(time->time_start), NULL);
	pthread_mutex_lock(&(time->time_start));
	// 뮤텍스 에러 확인
}