/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:43:40 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 15:43:54 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clear.h"

void	clear_all(t_system *system)
{
	long long	i;

	i = 0;
	pthread_mutex_destroy(&system->shared->print_status);
	while (i < system->philo_info->philos_num)
	{
		pthread_mutex_destroy(&system->forks[i].fork_mutex);
		i++;
	}
	free (system->forks);
	free (system->philos);
	free (system->philo_info);
	free (system->shared);
	free (system);
}
