/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:44:26 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/24 14:38:29 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_system	*init_system(int argc, char **argv)
{
	t_system	*system;

	system = (t_system *)malloc(sizeof(t_system));
	if (!system)
		return (NULL);
	init_info(argc, argv, system);
	if (!system->philo_info)
		return (NULL);
	init_philos(system->philo_info->philos_num, system);
	init_monitors(system->philo_info->philos_num, system);
	init_forks(system->philo_info->philos_num, system);
	init_shared(system);
	if (!system->philos || !system->philo_info || !system->shared \
		|| !system->forks || !system-> monitors)
		return (NULL);
	return (system);
}
