/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:20:46 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/01 03:09:40 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "init.h"
#include <sys/time.h>

void	put_philos_forks(t_system *philo_system)
{
	long long	i;
	long long	philos_num;
	t_philo		*philo;

	i = 0;
	philos_num = philo_system->philo_info->philos_num;
	philo = philo_system->philos;
	while (i < philos_num)
	{
		if (i == 0)
			philo[i].left_fork = &(philo_system->forks[philo_system->philo_info->philos_num - 1]);
		else
			philo[i].left_fork = &(philo_system->forks[i - 1]);
		if (i == 0)
			philo[i].right_fork = &(philo_system->forks[0]);
		else
			philo[i].right_fork = &(philo_system->forks[i]);
		i++;
	}
}

void	join_thread(t_system *system)
{
	int			*status;
	long long	i;
	t_philo		*philos;
	
	i = 0;
	philos = system->philos;
	while (i < system->philo_info->philos_num)
	{
		pthread_join(philos[i].philo_id, (void **)&status);
		i++;
	}
	// 요것도 에러처리
}

void	execution(t_system *philo_system)
{
	struct timeval	tv;
	
	put_philos_forks(philo_system);
	gettimeofday(&tv, NULL);
	philo_system->shared->starting_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	philo_system->shared->time_status = START;
	pthread_detach(philo_system->monitor_id);
	join_thread(philo_system);
}
