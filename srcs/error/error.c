/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:44:11 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/28 18:54:37 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_error(int num);

void	error(void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
	free (ptr1);
	free (ptr2);
	free (ptr3);
	free (ptr4);
}