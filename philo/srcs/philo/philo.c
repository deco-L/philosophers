/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/17 15:24:09 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	main(int argc, char **argv)
{
	t_root			root;

	if (!input(&root, argc, argv))
		return (EXIT_FAILURE);
	if (argc == 6)
		printf("input->count_task:%d\n", root.input->count_task);
	if (!init_thread(&root, root.input))
		return (EXIT_FAILURE);
	if (surveillance(root.input, root.thread))
		destory_thread(root.thread);
	free(root.input);
	return (EXIT_SUCCESS);
}
