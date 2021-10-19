/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:25:17 by dokkim            #+#    #+#             */
/*   Updated: 2021/10/19 16:06:07 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <validate.h>

int	validate_arg(int argc, char **argv)
{
	if (!(check_count(argc) && check_isdigit(argv) && check_range(argv)))
	{
		printf("ARGUMENTS ERROR\n");
		return (0);
	}
	return (1);
}

int	check_count(int argc)
{
	if (argc == 5 || argc == 6)
		return (1);
	else
		return (0);
}

int	check_isdigit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_range(char **argv)
{
	int	i;
	int	size;

	i = 0;
	while (argv[i])
	{
		size = ft_strlen(argv[i]);
		if (size > 19)
			return (0);
		if (ft_strcmp("9223372036854775807", argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
