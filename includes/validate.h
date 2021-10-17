/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:13:05 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/17 17:14:11 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
#define VALIDATE_H

int	validate_arg(int argc, char **argv);
int	check_count(int argc);
int	check_isdigit(char **argv);
int	check_range(char **argv);


#endif