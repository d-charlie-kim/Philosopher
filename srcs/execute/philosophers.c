/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:20:53 by dokkim            #+#    #+#             */
/*   Updated: 2021/11/03 18:21:44 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "struct.h"

void	ft_wait(long long time);
{
	while (i < time)
	{
		usleep();
		i++;
	}
}

void	eating()
{
	// print mutex lock
	// print eating 시간
	// print mutex unloc
	// ft_wait
}

void	take_fork()
{
	// l_fork mutex lock
	// 왼쪽 포크 쥔다.
	// print mutex lock
	// 왼쪽 포크 쥐었다고 print
	// print mutex unlock
	// r_fork mutex lock
	// 오른쪽 포크 쥔다
	// print mutex lock
	// 오른쪽 포크 쥐었다고 print
	// print mutex unlock
	// eating 함수로 갑니다
	// l_fork mutex unlock
	// r_fork mutex unlock


	// lock unlock 할때 매번 에러 체크 해줘야 합니다
}

void	ft_print()
{
	// 시간 계산 함수
	// 출력
}

void	sleeping()
{
	// print mutex lock
	// print 함수
	// print mutex unlock
	// ft_wait(시간)
}

void	thinking()
{
	// print mutex lock
	// print 함수
	// print mutex unlock
	// ft_wait(시간)
}

void	*philosophers(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	// 철학자가 아무도 죽지 않았거나
	// 먹어야 하는 횟수만큼 다 먹지 못했다면
	// 계속 돌아라
	pthread_mutex_lock(&(philo->philo_system->time->time_stat));
	while (system->shared->philo_status || (system->philo_info->max_eat > 0 && system->philos[i]->num_ate < system->philo_info->max_eat)
	{
		take_fork();
		sleeping();
		thinking();
	}
	// done 끝났다는거 보내줘야 함
}
