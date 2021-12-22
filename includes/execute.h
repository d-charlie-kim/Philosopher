/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:28:04 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 15:47:59 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include "struct.h"
# include "error.h"
# include "clear.h"

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

# define TAKEN 1
# define FREE 0

long long	get_elapsed_time(t_system *system);

void		*monitor(void *system);
int			is_done(t_system *system);
int			is_dead(t_system *system);

void		*philosophers(void *philosopher);
void		waiting(t_philo *philo, long long time);
void		eating(t_philo *philo);
void		taking_fork(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

void		printing(t_philo *philo, char *str);

int			join_thread(t_system *system);
int			execution(t_system *philo_system);

#endif
