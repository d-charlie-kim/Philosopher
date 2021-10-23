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

#include "init.h"
#include "struct.h"

t_system	*init_system(int argc, char **argv)
{
	t_system	*system;

	system = (t_system *)malloc(sizeof(t_system));
	if (!system)
		return (NULL);
	init_info(argc, argv, system);
	init_philos(argv[2], system);
	init_monitors(argv[2], system);
	init_forks(argv[2], system);
	init_shared(system);
	if (!system->philos || !system->philo_info || !system->shared \
		|| !system->forks || !system-> monitors)
		return (NULL);
	return (system);
}
