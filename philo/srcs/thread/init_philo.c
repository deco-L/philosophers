/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/16 15:30:30 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

bool	init_philo(t_thread *thread, t_input *input, int id)
{
	t_philo	*philo;

	philo = (t_philo *)ft_calloc(sizeof(t_philo), 1);
	if (malloc_error(philo))
		return (destory_thread(thread), false);
	philo->fork = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1);
	if (malloc_error(philo->fork))
		return (destory_thread(thread), false);
	pthread_mutex_init(philo->fork, NULL);
	philo->id = id;
	philo->fire = LONG_MAX;
	philo->time_die = input->time_die;
	philo->time_eat = input->time_eat;
	philo->time_sleep = input->time_sleep;
	philo->count_task = input->count_task;
	thread->philo = philo;
	return (true);
}
