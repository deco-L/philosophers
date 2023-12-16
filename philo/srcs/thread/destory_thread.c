/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/15 16:43:49 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

static void	destory_mutex(t_philo *philo)
{
	if (philo->fork)
	{
		pthread_mutex_destroy(philo->fork);
		free(philo->fork);
	}
	free(philo);
	return ;
}

void	destory_thread(t_thread *head)
{
	t_thread	*cw_thread;
	t_thread	*nw_thread;

	cw_thread = head;
	nw_thread = NULL;
	while (cw_thread != head || nw_thread != head)
	{
		nw_thread = cw_thread->next;
		if (cw_thread->philo)
			destory_mutex(cw_thread->philo);
		if (cw_thread->thread)
		{
			pthread_detach(*(cw_thread->thread));
			free(cw_thread->thread);
		}
		free(cw_thread);
		cw_thread = nw_thread;
	}
	return ;
}
