/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:20:53 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/28 19:21:28 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "struct.h"

void	ft_wait();

void	take_fork();
void	sleeping();
void	thinking();

void	*philosophers(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	// 철학자가 아무도 죽지 않았거나
	// 먹어야 하는 횟수만큼 다 먹지 못했다면
	// 계속 돌아라
	pthread_mutex_lock(&(philo->philo_system->time->time_stat));
	while (system->shared->philo_status || (system->philo_info->max_eat > 0 && system->philos[i]->num_ate < system->philo_info->max_eat)
	{
		take_fork();
		sleeping();
		ft_wait();
		thinking();
	}
}
