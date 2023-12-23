/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/23 16:52:32 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	main(int argc, char **argv)
{
	t_root			root;

	if (!input(&root, argc, argv))
		return (EXIT_FAILURE);
	if (!init_philo_root(&root))
		return (destory_philo_root(root.philo_root), EXIT_FAILURE);
	if (!init_thread(&root, root.input, root.philo_root))
		return (EXIT_FAILURE);
	if (surveillance(root.input, root.thread))
		destory_thread(root.thread, root.philo_root);
	free(root.input);
	return (EXIT_SUCCESS);
}
