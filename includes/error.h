/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:46:23 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/21 22:37:08 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>

# define INITIALIZATION_ERROR -100
# define EXECUTE_ERROR -200
# define ARGUMENTS_ERROR -300

int	ft_error(int num);

#endif
