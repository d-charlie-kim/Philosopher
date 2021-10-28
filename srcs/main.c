/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:24:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/28 19:27:07 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "init.h"
#include "validate.h"

#define ARGUMENTS_ERROR -1
#define INITIALIZATION_ERROR -2
#define EXECUTE_ERROR -3

int	main(int argc, char *argv[])
{
	t_system	*philo_system;

	if (!validate_arg(argc, argv))
		return (ft_error(ARGUMENTS_ERROR));
	philo_system = (t_system *)malloc(sizeof(t_system));
	if (init_system(argc, argv, philo_system))
		return (ft_error(INITIALIZATION_ERROR));
	setting_philo(philo_system); //이거를 밑에 execute에 넣어도 됨
	if (execute(philo_system))
		return (ft_error(EXECUTE_ERROR));
	// ending();
	printf("PROGRAM END\n");
	return (0);
}

ending(system)
{
	뮤텍스 전부 destroy 하고
	pthread 전부 끝내고
	malloc 전부 free 하고 나서
	return
}