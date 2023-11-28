/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/29 05:27:42 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static bool	check_number_args(int nbr)
{
	if (nbr != 5 && nbr != 6)
	{
		printf("Error\nUsage: ./philo number_of_philosophers time_to_die "\
				"time_to_eat time_to_sleep "\
				"[number_of_times_each_philosopher_must_eat]\n");
		return (true);
	}
	return (false);
}

static bool	check_args_is_num(int argc, char **argv)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (!str_isdigit(argv[index]))
		{
			printf("Error\nNot valid arguments\n");
			return (false);
		}
		index++;
	}
	return (true);
}

bool	input(t_philo *philo, int argc, char **argv)
{
	if (check_number_args(argc))
		return (false);
	if (check_args_is_num(argc, argv))
		return (false);
	memset(philo, 0, sizeof(t_philo));
	return (true);
}
