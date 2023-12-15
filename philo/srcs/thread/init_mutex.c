/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/15 14:28:50 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

bool	init_mutex(t_thread *thread, int id)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)ft_calloc(sizeof(t_mutex), 1);
	if (malloc_error(mutex))
		return (destory_thread(thread), false);
	mutex->fork = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1);
	if (malloc_error(mutex->fork))
		return (destory_thread(thread), false);
	mutex->id = id;
	pthread_mutex_init(mutex->fork, NULL);
	mutex->fire = LONG_MAX;
	thread->mutex = mutex;
	return (true);
}
