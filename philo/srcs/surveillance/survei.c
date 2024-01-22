/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   survei.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/22 18:11:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/survei.h"

bool	surveillance(t_input *input, t_thread *thread)
{
	int			release;
	t_thread	*head;
	t_philo		*philo;

	release = 0;
	head = thread;
	while (true)
	{
		if (thread == head)
			release = 0;
		philo = thread->philo;
		pthread_mutex_lock(philo->philo_root->death);
		if (philo->mealtime == 0)
			continue ;
		if (check_died(philo) && philo->status != END)
			return (destory_thread(thread, philo->philo_root), false);
		if (philo->status == END)
			release++;
		if (philo->count_task != 0 && release == input->number_philos)
			break ;
		pthread_mutex_unlock(philo->philo_root->death);
		thread = thread->next;
	}
	wait_thread(input, thread);
	return (true);
}
