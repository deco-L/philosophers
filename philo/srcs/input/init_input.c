/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/30 12:07:58 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

static void	assign_arguments(t_input *input, int argc, char **argv)
{
	input->number_philos = ft_atoi(argv[1]);
	input->time_die = ft_atoi(argv[2]);
	input->time_eat = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->count_task = ft_atoi(argv[5]);
	printf("input->number_philos:%d\n", input->number_philos);
	printf("input->time_die:%d\n", input->time_die);
	printf("input->time_eat:%d\n", input->time_eat);
	printf("input->time_sleep:%d\n", input->time_sleep);
	if (argc == 6)
		printf("input->count_task:%d\n", input->count_task);
	return ;
}

static bool	check_assigned_free(t_input *input)
{
	bool	judge;

	judge = false;
	if (input->number_philos <= 0)
		judge = true;
	else if (input->time_die < 0)
		judge = true;
	else if (input->time_eat < 0)
		judge = true;
	else if (input->time_sleep < 0)
		judge = true;
	else if (input->count_task < 0)
		judge = true;
	if (judge)
	{
		printf("Error\nInvalid argument.\n");
		free(input);
	}
	return (judge);
}

bool	init_input(t_root *root, int argc, char **argv)
{
	root->input = (t_input *)ft_calloc(sizeof(t_input), 1);
	if (malloc_error(root->input))
		return (false);
	assign_arguments(root->input, argc, argv);
	if (check_assigned_free(root->input))
		return (false);
	if (root->input != NULL)
		free(root->input);
	return (true);
}
