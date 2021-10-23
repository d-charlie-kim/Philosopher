/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:25:35 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/24 01:25:36 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INIT_H
# define INIT_H

#include "struct.h"

t_system	*init_system(int argc, char **argv);
void		init_info(int argc, char **argv, t_system *philo_system);
void		init_philos(long long num, t_system *philo_system);
void		init_monitors(long long num, t_system *philo_system);
void		init_forks(long long num, t_system *philo_system);
void		init_shared(t_system *philos_system);

#endif