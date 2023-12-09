/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/02 16:36:02 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	main(int argc, char **argv)
{
	t_root	root;

	if (!input(&root, argc, argv))
		return (EXIT_FAILURE);

	printf("input->number_philos:%d\n", root.input->number_philos);
	printf("input->time_die:%d\n", root.input->time_die);
	printf("input->time_eat:%d\n", root.input->time_eat);
	printf("input->time_sleep:%d\n", root.input->time_sleep);
	if (argc == 6)
		printf("input->count_task:%d\n", root.input->count_task);

	init_thread();
	if (root.input != NULL)
		free(root.input);
	return (EXIT_SUCCESS);
}
