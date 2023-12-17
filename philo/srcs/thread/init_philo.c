/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/17 19:36:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

bool	init_philo_root(t_root *root)
{
	t_philo_root	*philo_root;

	philo_root = (t_philo_root *)ft_calloc(sizeof(t_philo_root), 1);
	if (malloc_error(philo_root))
		return (free(root->input), false);
	philo_root->print = \
	(pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1);
	if (malloc_error(philo_root->print))
		return (free(root->input), false);
	pthread_mutex_init(philo_root->print, NULL);
	philo_root->death = \
	(pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1);
	if (malloc_error(philo_root->death))
		return (free(root->input), false);
	pthread_mutex_init(philo_root->death, NULL);
	root->philo_root = philo_root;
	return (true);
}

bool	init_philo(t_thread *thread, t_input *input, \
							t_philo_root *philo_root, int id)
{
	t_philo	*philo;

	philo = (t_philo *)ft_calloc(sizeof(t_philo), 1);
	if (malloc_error(philo))
		return (destory_thread(thread, philo_root), false);
	philo->fork = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1);
	if (malloc_error(philo->fork))
		return (destory_thread(thread, philo_root), false);
	pthread_mutex_init(philo->fork, NULL);
	philo->id = id;
	philo->fire = LONG_MAX;
	philo->time_die = input->time_die;
	philo->time_eat = input->time_eat;
	philo->time_sleep = input->time_sleep;
	philo->count_task = input->count_task;
	philo->philo_root = philo_root;
	thread->philo = philo;
	return (true);
}
