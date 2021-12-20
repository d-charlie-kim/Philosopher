/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:28:27 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/20 11:41:11 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void clear_mutex(t_system *system);

void clear_pthread(t_system *system);

void clear_memory(t_system *system);

void clear_all(t_system *system)
{
	clear_mutex(system);
	clear_pthread(system);
	clear_memory(system);
}
