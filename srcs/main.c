/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:24:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/24 14:34:31 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "validate.h"
#include "libft.h"
#include "init.h"

int	main(int argc, char *argv[])
{
	t_system	*philo_system;

	if (validate_arg(argc, argv))
		return (0);
	philo_system = init_system(argc, argv);
	// if (philo_system == NULL)
	// 	error("Initialization ERROR");
	// if (execute(philo_system->shared));
	// 	error("error why");
	printf("PROGRAM END\n");
	return (0);
}

	// 필로 / 포크 세팅 요거는 execute에서 해도 됨
	// 시간 세팅 준비는 해놓되, 필로 다 끝나면 돌아가니까 execute에서 한번에 해도 됨