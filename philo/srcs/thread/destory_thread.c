/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/14 16:18:08 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

static void	destory_mutex(t_mutex *mutex)
{
	if (mutex->fork)
	{
		pthread_mutex_destroy(mutex->fork);
		free(mutex->fork);
	}
	free(mutex);
	return ;
}

void	destory_thread(t_thread *head)
{
	t_thread	*cw_thread;
	t_thread	*nw_thread;

	cw_thread = head;
	nw_thread = NULL;
	free(head->mutex->start);
	while (cw_thread != head || nw_thread != head)
	{
		nw_thread = cw_thread->next;
		if (cw_thread->mutex)
			destory_mutex(cw_thread->mutex);
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
