/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:44:26 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 16:49:07 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	init_system(int argc, char **argv, t_system *system)
{
	if (!system)
		return (-1);
	if (init_info(argc, argv, system))
		return (-1);
	if (init_shared(system))
		return (-1);
	if (fork_setting(system->philo_info->philos_num, system))
		return (-1);
	if (philo_setting(system->philo_info->philos_num, system))
		return (-1);
	if (init_monitor(system))
		return (-1);
	return (0);
}
