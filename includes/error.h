/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:46:23 by dokkim            #+#    #+#             */
/*   Updated: 2021/12/21 17:46:54 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>

# define ARGUMENTS_ERROR -100
# define INITIALIZATION_ERROR -200
# define EXECUTE_ERROR -300

int	ft_error(int num);

#endif