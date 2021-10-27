/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:20:53 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/27 13:50:41 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "struct.h"

void	*philosophers(void *philo_system)
{
	t_system	*system;

	system = (t_system *)philo_system;
	// 철학자가 아무도 죽지 않았거나
	// 먹어야 하는 횟수만큼 다 먹지 못했다면
	// 계속 돌아라
	while (system->shared->philo_status || (system->philo_info->max_eat > 0 && system->philos[i]->num_ate < system->philo_info->max_eat)
	{
		take_fork();
		sleeping();
		ft_wait();
		thinking();
	}
}
