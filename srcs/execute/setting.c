/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:20:46 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/27 21:35:51 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>

void	setting_philo(t_philo *philo, t_system *philo_system)
{
		philo->left_fork = &(philo_system->forks[philo->philo_index - 1]);
		if (philo_system->philo_info->philos_num == 1)
			philo->right_fork = &(philo_system->forks[philo->philo_index - 1]);
		else
			philo->right_fork = &(philo_system->forks[philo->philo_index]);
}