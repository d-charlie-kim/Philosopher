/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:24:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/22 15:43:49 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_system	*philo_system;

	if (validate_arg(argc, argv))
		return (error_print(ARGUMENTS_ERROR));
	philo_system = (t_system *)malloc(sizeof(t_system));
	if (init_system(argc, argv, philo_system) == -1)
		return (error_print(INITIALIZATION_ERROR));
	if (execution(philo_system))
		return (error_print(EXECUTE_ERROR));
	clear_all(philo_system);
	printf("PROGRAM END\n");
	return (0);
}
