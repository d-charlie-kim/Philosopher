/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:24 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/19 16:33:55 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	info_init(int argc, char **argv, t_info *philo_info)
{
	philo_info->philos_num = ft_atoll(argv[1]);
	philo_info->time_to_die = ft_atoll(argv[2]);
	philo_info->time_to_eat = ft_atoll(argv[3]);
	philo_info->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		philo_info->max_eat = ft_atoll(argv[5]);
	else
		philo_info->max_eat = -1;
}
