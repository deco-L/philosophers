/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/02 15:43:28 by csakamot         ###   ########.fr       */
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
			printf("Error\nInvalid arguments\n");
			return (true);
		}
		index++;
	}
	return (false);
}

bool	input(t_root *root, int argc, char **argv)
{
	if (check_number_args(argc))
		return (false);
	if (check_args_is_num(argc, argv))
		return (false);
	memset(root, 0, sizeof(t_root));
	if (!init_input(root, argc, argv))
		return (false);
	return (true);
}
