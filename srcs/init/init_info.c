/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:24 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/20 20:55:46 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_info(int argc, char **argv, t_info *philo_info)
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

int	init_philos(t_system *philos_system)
{
	int			i;
	t_philos	*philos;
	t_info		*philos_info;

	i = 0;
	philo_info = philo_system->philos_info;
	philos_system->philos = (t_philo)malloc(sizeof(t_philo * philo_info->philos_num));
	philos = philo_system->philos;
	if (!philos)
		return ();
	while (i < philo_info->philos_num)
	{
		philos[i]->philo_num = i + 1;
		philos[i]->num_ate = 0;
		// pthread_create(philos[i].philo_id, NULL, (void *)function, philo_sywstem);
		i++;
	}
	// 쓰레드 잘 만들어졌는지 체크해야 됨
	return (0);
}

int	init_monitors(t_system *philos_system)
{
	t_forks		*forks;
	int			i;

	i = 0;
	philos_system->forks = (t_forks)malloc(sizeof())
}

int	init_forks(t_system *philos_system)
{

}

int	init_shared(t_system *philos_system)
{

}