/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:32:12 by dokkim            #+#    #+#             */
/*   Updated: 2021/11/16 02:47:09 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

# define SLEEPING 1
# define EATING 2
# define THINKING 3
# define GRAB_R 4
# define GRAB_L 5
# define DEAD 6

# define NOT_START 1
# define START 0

# define ALIVE 1
# define DONE 0

typedef struct s_system t_system;

typedef struct s_time;
{
	long tv_sec;
	long tv_usec;
}	t_time;

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
	int				time_status;
	long long		all_ate_philo_num;
	long long		starting_time;
	long long		current_time;
	long long		elapsed_time;
	pthread_mutex_t	print_status;
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
