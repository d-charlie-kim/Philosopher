/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:21:01 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 16:17:25 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	done_done_check(t_system *system)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < system->philo_info->philos_num)
	{
		if (system->philos[i].num_ate >= system->philo_info->max_eat)
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

int	is_done(t_system *system)
{
	int	i;
	int	count;

	count = done_done_check(system);
	if (count == system->philo_info->philos_num)
	{
		pthread_mutex_lock(&(system->shared->print_status));
		system->shared->philo_status = DONE;
		i = 0;
		while (i++ < system->philo_info->philos_num)
		{
			if (system->forks[i].fork_status == TAKEN)
				pthread_mutex_unlock(&(system->forks[i].fork_mutex));
			i++;
		}
		pthread_mutex_unlock(&(system->shared->print_status));
		return (1);
	}
	return (0);
}

int	is_dead(t_system *system)
{
	int			i;
	long long	time;
	t_philo		*philos;

	i = 0;
	philos = system->philos;
	while (i < system->philo_info->philos_num)
	{
		time = get_elapsed_time(system);
		if (time - philos[i].last_meal_time \
							> system->philo_info->time_to_die)
		{
			system->shared->philo_status = DEAD;
			pthread_mutex_lock(&(system->shared->print_status));
			printing(&(philos[i]), "is dead");
			pthread_mutex_unlock(&(system->shared->print_status));
			if (philos[i].left_fork->fork_status == TAKEN)
				pthread_mutex_unlock(&(philos[i].left_fork->fork_mutex));
			if (philos[i].right_fork->fork_status == TAKEN)
				pthread_mutex_unlock(&(philos[i].right_fork->fork_mutex));
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor(void *system)
{
	t_system	*philo_system;

	philo_system = (t_system *)system;
	while (philo_system->shared->time_status == NOT_START)
		;
	while (philo_system->shared->philo_status != ERROR)
	{
		if (philo_system->philo_info->max_eat >= 0 && is_done(philo_system))
			break ;
		if (is_dead(philo_system))
			break ;
	}
	return (NULL);
}
