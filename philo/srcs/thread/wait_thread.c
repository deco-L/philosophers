/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/15 11:55:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

void	wait_thread(t_input *input, t_thread *thread)
{
	int	index;

	index = 0;
	while (index < input->number_philos)
	{
		pthread_join(*(thread->thread), NULL);
		free(thread->thread);
		thread->thread = NULL;
		thread = thread->next;
		index++;
	}
	return ;
}
