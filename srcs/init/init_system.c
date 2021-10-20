/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:44:26 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/20 20:36:48 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_system	*init_system(int argc, char **argv)
{
	t_system	*philo_system;

	philo_system = (t_system)malloc(sizeof(t_system));
	if (!philo_system)
		return (NULL);
	philo_system->philo_info = (t_info)malloc(sizeof(t_info));
	if (!philo_system->philo_info)
		return (NULL);
	init_info(argc, argv, philo_system->philo_info);
	init_philos(philo_system);
	init_monitors(philo_system);
	init_forks(philo_system);
	init_shared(philo_system);
	// 위에 초기화 및 시작준비가 잘 되었는지 확인하는 단계 필요
	return (philo_system);
}
