/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:24 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/21 23:55:35 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "error.h"

int	init_info(int argc, char **argv, t_system *philo_system)
{
	t_info	*info;

	philo_system->philo_info = (t_info *)malloc(sizeof(t_info));
	if (!philo_system->philo_info)
	{
		free (philo_system);
		return (-1);
	}
	info = philo_system->philo_info;
	info->philos_num = ft_atoll(argv[1]);
	info->time_to_die = ft_atoll(argv[2]);
	info->time_to_eat = ft_atoll(argv[3]);
	info->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		info->max_eat = ft_atoll(argv[5]);
	else
		info->max_eat = -1;
	return (0);
}

int	init_shared(t_system *philo_system)
{
	t_shared	*shared;

	philo_system->shared = (t_shared *)malloc(sizeof(t_shared));
	if (!philo_system->shared)
	{
		free (philo_system->philo_info);
		free (philo_system);
		return (-1);
	}
	shared = philo_system->shared;
	shared->philo_status = ALIVE;
	shared->elapsed_time = 0;
	shared->all_ate_num = 0;
	shared->starting_time = 0;
	shared->time_status = NOT_START;
	if (pthread_mutex_init(&(shared->print_status), NULL))
		return (-1);
	return (0);
}

int	init_forks(long long num, t_system *philo_system)
{
	long long	i;
	t_fork	*fork;

	i = 0;
	philo_system->forks = (t_fork *)malloc(sizeof(t_fork) * num);
	if (!philo_system->forks)
	{
		pthread_mutex_destroy(&(philo_system->shared->print_status));
		free (philo_system->philo_info);
		free (philo_system->shared);
		free (philo_system);
		return (-1);
	}
	fork = philo_system->forks;
	while (i < num)
	{
		fork->fork_status = FREE;
		if (pthread_mutex_init(&((fork[i]).fork_mutex), NULL))
		{
			while (i >= 0)
			{
				pthread_mutex_destroy(&((fork[i]).fork_mutex));
				i--;
			}
			free (philo_system->forks);
			pthread_mutex_destroy(&(philo_system->shared->print_status));
			free (philo_system->philo_info);
			free (philo_system->shared);
			free (philo_system);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_philos(long long num, t_system *philo_system)
{
	long long	i;
	t_philo		*philo;

	i = 0;
	philo_system->philos = (t_philo *)malloc(sizeof(t_philo) * num);
	if (!philo_system->philos)
	{
		while (i < philo_system->philo_info->philos_num)
		{
			pthread_mutex_destroy(&((philo_system->forks[i]).fork_mutex));
			i++;
		}
		free (philo_system->forks);
		pthread_mutex_destroy(&(philo_system->shared->print_status));
		free (philo_system->philo_info);
		free (philo_system->shared);
		free (philo_system);
		return (-1);
	}
	philo = philo_system->philos;
	while (i < num)
	{
		(philo[i]).last_meal_time = 0;
		(philo[i]).philo_index = i + 1;
		(philo[i]).num_ate = 0;
		(philo[i]).philo_system = philo_system;
		if (pthread_create(&(philo[i].philo_id), NULL, philosophers, &philo[i]))
		{
			philo_system->shared->philo_status = ERROR;
			philo_system->shared->time_status = ERROR;
			i = 0;
			while (i < philo_system->philo_info->philos_num)
			{
				pthread_mutex_destroy(&((philo_system->forks[i]).fork_mutex));
				i++;
			}
			free (philo_system->forks);
			pthread_mutex_destroy(&(philo_system->shared->print_status));
			free (philo_system->philo_info);
			free (philo_system->shared);
			free (philo_system);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_monitor(t_system *philo_system)
{
	int	i;

	i = 0;
	if (pthread_create(&(philo_system->monitor_id), NULL, monitor, philo_system))
	{
		philo_system->shared->philo_status = ERROR;
		philo_system->shared->time_status = ERROR;
		i = 0;
		while (i < philo_system->philo_info->philos_num)
		{
			pthread_mutex_destroy(&((philo_system->forks[i]).fork_mutex));
			i++;
		}
		free (philo_system->forks);
		pthread_mutex_destroy(&(philo_system->shared->print_status));
		free (philo_system->philo_info);
		free (philo_system->shared);
		free (philo_system);
		return (-1);
	}
	return (0);
}
