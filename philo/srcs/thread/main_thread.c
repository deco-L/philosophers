/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/15 13:37:36 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"


void	*routine(void *arg)
{
	t_mutex			*mutex;
	// struct timeval	tv;

	mutex = arg;
	printf("[%d]ready.\n", mutex->id);
	// printf("[%d]start.%d\n", mutex->id, *(mutex->start));
	// gettimeofday(&tv, NULL);
	// printf("tv_sec:%ld, tv_usec:%ld\n", tv.tv_sec, tv.tv_usec);
	return (NULL);
}
