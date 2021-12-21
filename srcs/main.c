/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:24:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/21 22:56:11 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	main(int argc, char *argv[])
{
	t_system	*philo_system;

	if (validate_arg(argc, argv))
		return (ft_error(ARGUMENTS_ERROR));
	philo_system = (t_system *)malloc(sizeof(t_system));
	if (init_system(argc, argv, philo_system) == -1)
		return (ft_error(INITIALIZATION_ERROR));
	if (execution(philo_system))
		return (ft_error(EXECUTE_ERROR));
	clear_all(philo_system);
	printf("PROGRAM END\n");
	return (0);
}
