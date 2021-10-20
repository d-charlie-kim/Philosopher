/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:24:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/20 20:47:56 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char *argv[])
{
	t_system	*philo_system;

	if (validate_arg(argc, argv))
		return (0);
	philo_system = init_system(argc, argv);
	if (philo_system == NULL)
		error("Initialization ERROR");
	// 그럼 1단계 끝남.
	time 초기화 혹은 동기화
	// 그럼 1.5단계 끝남.

	execute시작.
	//그럼 2단계 끝남
	에러처리 및 출력 관리
	// 그럼 3단계 끝남

	마무리 정리 / 놈 / 깔끔하게 / makefile
	// 그럼 4단계 끝남

	
	if (execute(philo_system))
		return (0);
	printf("PROGRAM END\n");
	return (0);
}


	필로 / 포크 세팅 요거는 execute에서 해도 됨
	시간 세팅 준비는 해놓되, 필로 다 끝나면 돌아가니까 execute에서 한번에 해도 됨