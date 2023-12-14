/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/14 15:34:28 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	main(int argc, char **argv)
{
	t_root			root;
	// struct timeval	tv;

	if (!input(&root, argc, argv))
		return (EXIT_FAILURE);

	printf("input->number_philos:%d\n", root.input->number_philos);
	printf("input->time_die:%d\n", root.input->time_die);
	printf("input->time_eat:%d\n", root.input->time_eat);
	printf("input->time_sleep:%d\n", root.input->time_sleep);
	if (argc == 6)
		printf("input->count_task:%d\n", root.input->count_task);
	// gettimeofday(&tv, NULL);
	// printf("tv_sec:%ld, tv_usec:%ld\n", tv.tv_sec, tv.tv_usec);
	if (!init_thread(&root, root.input))
	{
		free(root.input);
		return (EXIT_FAILURE);
	}
	printf("hello\n");
	start_thread(root.thread);
	wait_thread(root.input, root.thread);
	destory_thread(root.thread);
	free(root.input);
	return (EXIT_SUCCESS);
}
