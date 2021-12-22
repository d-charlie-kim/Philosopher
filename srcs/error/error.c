/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:44:11 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 16:03:42 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	error_print(int num)
{
	if (num == -100)
		printf("ERROR : INITIALIZATION ERROR\n");
	else if (num == -200)
		printf("ERROR : EXECUTION ERROR\n");
	else if (num == -300)
		printf("ERROR : ARGUMENTS ERROR\n");
	return (-1);
}

int	ft_error(t_system *system)
{
	system->shared->philo_status = ERROR;
	system->shared->time_status = ERROR;
	join_thread(system);
	clear_all(system);
	return (-1);
}
