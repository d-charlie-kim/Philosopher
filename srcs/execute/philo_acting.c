/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:44:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 16:49:16 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	if (philo->philo_system->shared->philo_status != ALIVE)
	{
		pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
		return ;
	}
	printing(philo, "is sleeping");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
	waiting(philo, philo->philo_system->philo_info->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	if (philo->philo_system->shared->philo_status != ALIVE)
	{
		pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
		return ;
	}
	printing(philo, "is thinking");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
}

void	waiting(t_philo *philo, long long time)
{
	long long	i;
	long long	current_time;

	i = 0;
	current_time = get_elapsed_time(philo->philo_system);
	while (i < time * 10)
	{
		usleep(50);
		if (get_elapsed_time(philo->philo_system) - current_time >= time)
			break ;
		usleep(50);
		if (get_elapsed_time(philo->philo_system) - current_time >= time)
			break ;
		i++;
	}
}

void	eating(t_philo *philo)
{
	philo->last_meal_time = get_elapsed_time(philo->philo_system);
	philo->num_ate++;
	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	if (philo->philo_system->shared->philo_status != ALIVE)
	{
		pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
		pthread_mutex_unlock(&(philo->left_fork->fork_mutex));
		pthread_mutex_unlock(&(philo->right_fork->fork_mutex));
		return ;
	}
	printing(philo, "is eating");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
	waiting(philo, philo->philo_system->philo_info->time_to_eat);
	pthread_mutex_unlock(&(philo->left_fork->fork_mutex));
	philo->left_fork->fork_status = FREE;
	pthread_mutex_unlock(&(philo->right_fork->fork_mutex));
	philo->right_fork->fork_status = FREE;
}

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->fork_mutex));
	philo->left_fork->fork_status = TAKEN;
	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	if (philo->philo_system->shared->philo_status == ALIVE)
		printing(philo, "has taken a left fork");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
	pthread_mutex_lock(&(philo->right_fork->fork_mutex));
	philo->right_fork->fork_status = TAKEN;
	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	if (philo->philo_system->shared->philo_status != ALIVE)
	{
		pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
		pthread_mutex_unlock(&(philo->left_fork->fork_mutex));
		pthread_mutex_unlock(&(philo->right_fork->fork_mutex));
		return ;
	}
	printing(philo, "has taken a right fork");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
}
