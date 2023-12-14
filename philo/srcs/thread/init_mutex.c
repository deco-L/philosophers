/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/14 14:57:22 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

bool	init_mutex(t_thread *thread)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)ft_calloc(sizeof(t_mutex), 1);
	if (!mutex)
		return (false);
	mutex->fork = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1);
	if (!mutex->fork)
		return (false);
	pthread_mutex_init(mutex->fork, NULL);
	thread->mutex = mutex;
	return (true);
}
