/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:21:01 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/01 02:45:35 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	is_done(t_system *system)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < system->philo_info->philos_num)
	{
		if (system->philos[i].num_ate >= system->philo_info->max_eat)
			count++;
		else
			break ;
		i++;
	}
	if (count == system->philo_info->philos_num)
	{
		pthread_mutex_lock(&(system->shared->print_status));
		system->shared->philo_status = DONE;
		return (1);
	}
	return (0);
}

int	is_dead(t_system *system)
{
	int			i;
	long long	time;

	i = 0;
	while (i < system->philo_info->philos_num)
	{
		time = get_elapsed_time(system);
		if (time - system->philos[i].last_meal_time > system->philo_info->time_to_die)
		{
			system->shared->philo_status = DEAD;
			pthread_mutex_lock(&(system->shared->print_status));
			printing(&(system->philos[i]), "is dead");
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor(void *system)
{
	t_system	*philo_system;

	philo_system = (t_system *)system;
	while (philo_system->shared->time_status == NOT_START)
		;
	while (1)
	{
		if (philo_system->philo_info->max_eat >= 0 && is_done(philo_system))
			break ;
		if (is_dead(philo_system))
			break ;
	}
	return (NULL);
	// clear_all 함수 로 가는 거

	// 이게 만약에 딜레이가 더 심해지는데 큰 공헌을 한다면
	// 모니터를 두개로 나눠서 죽이는 모니터와 끝내는 모니터 두개를 두자
}
