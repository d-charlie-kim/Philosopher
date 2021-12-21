/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:44:11 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/21 17:33:43 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	ft_error(int num)
{
	if (num == -100)
		printf("ERROR : INITIALIZATION ERROR\n");
	else if (num == -200)
		printf("ERROR : EXECUTION ERROR\n");
	else if (num == -300)
		printf("ERROR : ARGUMENTS ERROR\n");
	return (-1);
}
