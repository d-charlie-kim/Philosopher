/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:20:46 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/28 17:43:47 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "init.h"

void	setting_philo(t_system *philo_system)
{
	long long	i;
	long long	philos_num;
	t_philo		*philo;

	philos_num = philo_system->philo_info->philos_num;
	philo = philo_system->philos;
	while (i < philos_num)
	{
		philo[i].left_fork = &(philo_system->forks[philo[i].philo_index - 1]);
		if (philos_num == 1)
			philo->right_fork = &(philo_system->forks[philo[i].philo_index - 1]);
		else
			philo->right_fork = &(philo_system->forks[philo[i].philo_index]);
		i++;
	}
}