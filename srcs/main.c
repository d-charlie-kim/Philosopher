/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:24:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/19 16:09:52 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char *argv[])
{
	t_info	philo_info;

	if (validate_arg(argc, argv))
		return (0);
	info_init(argc, argv, &philo_info);
	if (execute(philo_info))
		return (0);
	printf("PROGRAM END\n");
	return (0);
}


	필로 / 포크 세팅 요거는 execute에서 해도 됨
	시간 세팅 준비는 해놓되, 필로 다 끝나면 돌아가니까 execute에서 한번에 해도 됨