/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:20:53 by dokkim            #+#    #+#             */
/*   Updated: 2021/11/18 22:28:36 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "struct.h"
#include <unistd.h>

void	waiting(t_philo *philo, long long time)
{
	long long	i;
	long long	current_time;

	i = 0;
	current_time = get_elapsed_time(philo);
	while (i < time * 10)
	{
		usleep(50);
		if (get_elapsed_time(philo) - current_time >= time)
			break ;
		usleep(50);
		if (get_elapsed_time(philo) - current_time >= time)
			break ;
		i++;
	}
}

void	eating(t_philo *philo)
{
	philo->num_ate++;
	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	printing(philo, "is eating");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
	waiting(philo, philo->philo_system->philo_info->time_to_eat);
}

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->fork_mutex));

	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	printing(philo, "has taken a left fork");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
	
	pthread_mutex_lock(&(philo->right_fork->fork_mutex));

	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	printing(philo, "has taken a right fork");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));

	eating(philo);

	pthread_mutex_unlock(&(philo->left_fork->fork_mutex));
	pthread_mutex_unlock(&(philo->right_fork->fork_mutex));

	// lock unlock 할때 매번 에러 체크 해줘야 합니다
}

void	printing(t_philo *philo, char *str)
{
// 	long long	elapsed_time;
// 	elapsed_time = get_elapsed_time(philo);
	printf("%5lldms  Philo No.%4lld ---->", get_elapsed_time(philo), philo->philo_index);
	printf(" %s\n", str);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&(philo->philo_system->shared->print_status));
	printing(philo, "is sleeping");
	pthread_mutex_unlock(&(philo->philo_system->shared->print_status));
	waiting(philo, philo->philo_system->philo_info->time_to_sleep);
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
	if (philo->philo_index % 2 == 0)
		waiting(philo, (philo->philo_system->philo_info->time_to_eat) / 2);
	while (philo->philo_system->shared->philo_status == ALIVE && (philo->philo_system->philo_info->max_eat < 0 || philo->num_ate < philo->philo_system->philo_info->max_eat))
	{
		taking_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	printf(":::::::: DONE OR DEAD ::::::::::\n");
	if (philo->num_ate == philo->philo_system->philo_info->max_eat)
		philo->philo_system->shared->all_ate_num++;
		// mutex 필요
		// all_ate_num이 철학자 수 만큼 되면 종료
		// 다 먹은 철학자가 몇명인가
	return (NULL);
}
