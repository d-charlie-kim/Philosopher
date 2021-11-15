/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:21:01 by dokkim            #+#    #+#             */
/*   Updated: 2021/11/14 22:39:17 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	monitor(void *system)
{
	t_system	*system;

	system = (t_system *)system;
	while (1)
	{
	}


	// 모니터는 while 문으로 열심히 필로가 죽었는지 확인한다
	// 죽었다면 szz
	// 죽은 철학자 출력 후 mutex unlock 하지 않고
	// 다 죽이기 시작한다.
	// 다 죽인뒤에는 모두 프리해주는 함수 호출
	// 그리고 마무리.

	// 마무리라 함은 어떻게 하는가. 뭘 어떻게 해 그냥 마무리 되는거지
}
