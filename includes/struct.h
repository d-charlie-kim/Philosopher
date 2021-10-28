/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:32:12 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/28 17:45:19 by dokkim           ###   ########.fr       */
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
	long long		current_time;
	pthread_mutex_t	print_status;
	pthread_mutex_t	time_start;
}	t_shared;

typedef struct s_fork
{
	long long		fork_index;
	pthread_mutex_t	mutex_id;
}	t_fork;

typedef struct s_philo
{
	long long	philo_index;
	long long	num_ate;
	pthread_t	philo_id;
	t_fork		*right_fork;
	t_fork		*left_fork;
	t_system	*philo_system;
}	t_philo;

typedef struct s_system
{
	pthread_t	monitor_id;
	t_philo		*philos;
	t_info		*philo_info;
	t_shared	*shared;
	t_fork		*forks;
}	t_system;

void	setting_philo(t_system *philo_system);

#endif
