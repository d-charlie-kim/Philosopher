/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:44:26 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/28 18:58:31 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	init_system(int argc, char **argv, t_system *system)
{
	if (!system) // 널 포인터인지 체크
		return (-1);
	if (init_info(argc, argv, system))  // 말록 하나
		return (-1);
	if (init_shared(system)) // 말록 하나와 뮤텍스 init 두개와 mutex lock 하나
		return (-1);
	if (init_forks(system->philo_info->philos_num, system)) // 말록 하나 와 뮤텍스 여러개
		return (-1);
	if (init_philos(system->philo_info->philos_num, system)) // 말록 하나와 쓰레드 여러개
		return (-1);
	if (init_monitor(system)) // 쓰레드 하나
		return (-1);
	return (0);
}
