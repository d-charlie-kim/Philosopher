/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:44:11 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/20 11:25:18 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"

void	ft_error(int num)
{
	if (num == INITIALIZATION_ERROR)
		printf("ERROR : INITIALIZATION ERROR\n");
	else if (num == EXECUTE_ERROR)
		printf("ERROR : EXECUTION ERROR\n");
	else if (num == ARGUMENTS_ERROR)
		printf("ERROR : ARGUMENTS ERROR\n");
	return (-1);
}

void	error(void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
	free (ptr1);
	free (ptr2);
	free (ptr3);
	free (ptr4);
}