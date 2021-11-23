/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:28:04 by dokkim            #+#    #+#             */
/*   Updated: 2021/11/18 21:46:14 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "struct.h"
# include "philo.h"

void	execution(t_system *philo_system);
void	waiting(t_philo *philo, long long time);
void	eating(t_philo *philo);
void	taking_fork(t_philo *philo);
void	printing(t_philo *philo, char *str);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	*philosophers(void *philosopher);

# endif
