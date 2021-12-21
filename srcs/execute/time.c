/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:47:31 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/21 17:49:24 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

long long	get_elapsed_time(t_system *system)
{
	long long		current_time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time - system->shared->starting_time);
}
