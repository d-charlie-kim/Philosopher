/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:20:53 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/21 17:49:16 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

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
	// lock unlock 할때 매번 에러 체크 해줘야 합니다
}

void	printing(t_philo *philo, char *str)
{
	long long	time;
	
	time = get_elapsed_time(philo->philo_system);
	if (time == ERROR)
	{
		return ;
		// 에러처리 해주세요
	}
	printf("%5lldms  Philo No.%3lld ---->", time, philo->philo_index);
	printf(" %s\n", str);
}

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

void	*philosophers(void *philosopher)
{
	t_philo			*philo;

	philo = (t_philo *)philosopher;
	while (philo->philo_system->shared->time_status == NOT_START)
		;
	if (philo->philo_index % 2 == 0)
		waiting(philo, (philo->philo_system->philo_info->time_to_eat) / 2);
	while (philo->philo_system->shared->philo_status == ALIVE)
	{
		if (philo->philo_system->shared->philo_status == ALIVE)
			taking_fork(philo);
		if (philo->philo_system->shared->philo_status == ALIVE)
			eating(philo);
		if (philo->philo_system->shared->philo_status == ALIVE)
			sleeping(philo);
		if (philo->philo_system->shared->philo_status == ALIVE)
			thinking(philo);
	}
	return (NULL);
}



/*
	1. 철학자 전부가 해당 숫자만큼 다 먹으면 끝내는 파트 -> 모니터 안으로 들어감
	2. 철학자 죽이고 감시하는 모니터 파트 (dead 출력까지 들어감)
	3. 정상 종료 했을때, 전부 destroy free 해주는 파트
	4. 에러 처리 (lock unlock gettimeofday 또 뭐 있지)
	5. 출력물 색상 추가
	6. 놈 정리
*/
