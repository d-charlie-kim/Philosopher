/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:20:53 by dokkim            #+#    #+#             */
/*   Updated: 2021/11/16 03:31:16 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "struct.h"

void	waiting(long long time)
{
	long long	i;
	long long	j;

	i = 0;
	while (i < time)
	{
		j = 0;
		while (j < 1000)
		{
			usleep(1);
			j++;
		}
		i++;
	}
}

void	eating(t_philo *philo)
{
	philo->num_ate++;
	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	printing(philo, "is eating");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
	waiting(philo->philo_system->philo_info->time_to_eat);
}

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork));

	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	printing(philo, "has taken a left fork");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
	
	pthread_mutex_lock(&(philo->right_fork));

	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	printing(philo, "has taken a right fork");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));

	eating(philo);

	pthread_mutex_unlock(&(philo->left_fork));
	pthread_mutex_unlock(&(philo->right_fork));

	// lock unlock 할때 매번 에러 체크 해줘야 합니다
}

void	printing(t_philo *philo, char *str)
{
	long long	elapsed_time;
	elapsed_time = get_elapsed_time(philo->philo_system->shared);
	printf("%lldms  Philo No.%lld ---->", elapsed_time, philo->philo_index);
	printf(" %s\n", str);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	printing(philo, "is sleeping");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
	waiting(philo->philo_system->philo_info->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	printing(philo, "is thinking");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
}

void	*philosophers(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	while (philo->philo_system->shared->time_status == NOT_START)
		;
	while (philo->philo_system->shared->philo_status == ALIVE \
	|| (philo->philo_system->shared->all_ate_philo_num > 0 \
	&& philo->num_ate < philo->philo_system->shared->all_ate_philo_num))
	{
		taking_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	if (philo->num_ate == philo->philo_system->shared->all_ate_philo_num)
		philo->philo_system->shared->all_ate_philo_num++;
 }
