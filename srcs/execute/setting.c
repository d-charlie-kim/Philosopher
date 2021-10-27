/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:20:46 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/27 21:26:13 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	setting_philo(t_philo *philo, t_system *philo_system)
{
	long long	i;
	long long	philos_num;

	i = 0;
	philos_num = philo_system->philo_info->philos_num;
	while (i < philos_num)
	{
		philo->left_fork = &(philo_system->forks[i]);
		if (philos_num != 1)
			philo->right_fork = &(philo_system->forks[philos_num - i]);
		else
			philo->right_fork = &(philo_system->forks[i]);
		i++;
	}
}