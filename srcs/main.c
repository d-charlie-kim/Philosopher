/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:24:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/11/16 21:08:18 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "init.h"
#include "validate.h"
#include "execute.h"

#define ARGUMENTS_ERROR -1
#define INITIALIZATION_ERROR -2
#define EXECUTE_ERROR -3

int	main(int argc, char *argv[])
{
	t_system	*philo_system;


	validate_arg(argc, argv);
	// if (!validate_arg(argc, argv))
	// 	return (ft_error(ARGUMENTS_ERROR));
	philo_system = (t_system *)malloc(sizeof(t_system));
	init_system(argc, argv, philo_system);
	// if (init_system(argc, argv, philo_system))
	// 	return (ft_error(INITIALIZATION_ERROR));
	execution(philo_system);
	// 	return (ft_error(EXECUTE_ERROR));
	// ending();
	while (1);
	printf("PROGRAM END\n");
	return (0);
}

// ending(system)
// {
// 	뮤텍스 전부 destroy 하고
// 	pthread 전부 끝내고
// 	malloc 전부 free 하고 나서
// 	return
// }
