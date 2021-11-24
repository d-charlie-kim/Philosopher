/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:25:35 by dokkim            #+#    #+#             */
/*   Updated: 2021/11/24 18:10:39 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INIT_H
# define INIT_H

# include "struct.h"
# include "libft.h"
# include "philo.h"
# include <stdlib.h>

int	init_system(int argc, char **argv, t_system *system);
int	init_info(int argc, char **argv, t_system *philo_system);
int	init_philos(long long num, t_system *philo_system);
int	init_monitor(t_system *philo_system);
int	init_forks(long long num, t_system *philo_system);
int	init_shared(t_system *philos_system);

#endif
