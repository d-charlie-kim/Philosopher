/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:47:31 by dokkim            #+#    #+#             */
/*   Updated: 2021/11/16 19:45:14 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <struct.h>

// void	time_check()
// {
	// 죽었니 살았니 
// }

long long	get_elapsed_time(t_philo *philo)
{
	long long		current_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time - philo->philo_system->shared->starting_time);
}
