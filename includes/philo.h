/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:20:16 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/19 16:35:22 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_info
{
	long long	philos_num;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	max_eat;
}	t_info;

typedef struct s_philo
{
	long long	philo_num;
	long long	right_fork;
	long long	left_fork;
	long long	num_ate;
	int			status;
}	t_philo;

typedef struct s_system
{
	"포크 포인터들이 담겨 있는 배열";
	t_philo	*philos;
	t_info	*philo_info;
}	t_system;

typedef struct s_time
{
	시계 관련
}	t_time;

#endif