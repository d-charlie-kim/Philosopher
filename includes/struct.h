/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:32:12 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/27 21:26:41 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct s_system t_system;

typedef struct s_info
{
	long long	philos_num;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	max_eat;
}	t_info;

typedef struct s_shared
{
	int				philo_status;
	long long		all_ate_philo_num;
	pthread_mutex_t	print_status;
	long long		current_time;
	long long		time;
}	t_shared;

typedef struct s_fork
{
	pthread_mutex_t	mutex_id;
	long long		fork_index;
}	t_fork;


typedef struct s_time
{
	pthread_mutex_t	time_start;
	long long		current_time;
	long long		starting_time;
}	t_time;

typedef struct s_philo
{
	long long	philo_index;
	pthread_t	philo_id;
	t_fork		*right_fork;
	t_fork		*left_fork;
	long long	num_ate;
	t_system	*philo_system;
}	t_philo;

typedef struct s_monitor
{
	pthread_t	monitor_id;
	long long	monitor_num;
	t_philo		*monitoring_philo;
	t_system	*philo_system;
}	t_monitor;

typedef struct s_system
{
	t_philo		*philos;
	t_monitor	*monitors;
	t_info		*philo_info;
	t_shared	*shared;
	t_fork		*forks;
	t_time		*time;
}	t_system;

void	setting_philo(t_philo *philo, t_system *philo_system);

#endif
