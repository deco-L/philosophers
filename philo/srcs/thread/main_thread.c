/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/14 17:26:37 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

bool	start_thread(t_thread *thread)
{
	sleep(2);
	printf("wake up\n");
	*(thread->mutex->start) = START;
	return (true);
}

void	*routine(void *arg)
{
	t_mutex	*mutex;

	mutex = arg;
	printf("[%d]ready.%d\n", mutex->id, *(mutex->start));
	while (!*(mutex->start))
	{
		printf("%d\n", *(mutex->start));
		sleep(1);
	}
	printf("[%d]start.%d\n", mutex->id, *(mutex->start));
	return (NULL);
}
