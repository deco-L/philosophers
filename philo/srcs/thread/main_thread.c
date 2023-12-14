/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/14 17:56:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

static void	yoooi(int *index)
{
	while (!(*index))
		;
	return ;
}

bool	don(t_thread *thread)
{
	usleep(2000000);
	printf("wake up\n");
	*(thread->mutex->start) = START;
	return (true);
}

void	*routine(void *arg)
{
	t_mutex			*mutex;
	struct timeval	tv;

	mutex = arg;
	printf("in_routine\n");
	printf("[%d]ready.%d\n", mutex->id, *(mutex->start));
	yoooi(mutex->start);
	printf("[%d]start.%d\n", mutex->id, *(mutex->start));
	gettimeofday(&tv, NULL);
	printf("tv_sec:%ld, tv_usec:%ld\n", tv.tv_sec, tv.tv_usec);
	return (NULL);
}
