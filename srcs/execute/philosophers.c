/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:20:53 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 16:46:52 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	*philosophers(void *philosopher)
{
	t_philo			*philo;

	philo = (t_philo *)philosopher;
	while (philo->philo_system->shared->time_status == NOT_START)
		;
	if (philo->philo_index % 2 == 0)
		waiting(philo, (philo->philo_system->philo_info->time_to_eat) / 2);
	while (philo->philo_system->shared->philo_status == ALIVE)
	{
		if (philo->philo_system->shared->philo_status == ALIVE)
			taking_fork(philo);
		if (philo->philo_system->shared->philo_status == ALIVE)
			eating(philo);
		if (philo->philo_system->shared->philo_status == ALIVE)
			sleeping(philo);
		if (philo->philo_system->shared->philo_status == ALIVE)
			thinking(philo);
	}
	return (NULL);
}
