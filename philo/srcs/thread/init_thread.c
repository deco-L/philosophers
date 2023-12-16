/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/15 16:46:13 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

static bool	set_start_time(t_thread *thread)
{
	t_thread		*head;
	struct timeval	tv;

	head = thread;
	if (gettimeofday(&tv, NULL))
		return (destory_thread(head), false);
	head->philo->fire = tv.tv_sec + 5;
	thread = thread->next;
	while (thread != head)
	{
		thread->philo->fire = head->philo->fire;
		thread = thread->next;
	}
	return (true);
}

static t_thread	*new_thread(t_thread *head, t_input *input, int id)
{
	t_thread	*new;

	new = (t_thread *)ft_calloc(sizeof(t_thread), 1);
	if (malloc_error(new))
		return (destory_thread(head), NULL);
	if (!init_philo(new, input, id))
		return (destory_thread(head), NULL);
	new->thread = (pthread_t *)ft_calloc(sizeof(pthread_t), 1);
	if (malloc_error(new->thread))
		return (destory_thread(head), NULL);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

static void	add_back_thread(t_thread *head, t_thread *new)
{
	t_thread	*tail;

	tail = head->prev;
	if (!tail)
	{
		head->prev = new;
		head->next = new;
		new->prev = head;
		new->next = head;
	}
	else
	{
		tail->next = new;
		head->prev = new;
		new->prev = tail;
		new->next = head;
	}
	return ;
}

static bool	create_thread(t_thread *thread, t_input *input)
{
	int			index;
	t_thread	*head;
	void		*philo;

	index = 0;
	head = thread;
	while (index < input->number_philos)
	{
		thread->philo->right = thread->prev->philo->fork;
		thread->philo->left = thread->next->philo->fork;
		philo = thread->philo;
		if (pthread_create(thread->thread, NULL, routine, philo) != 0)
			return (destory_thread(head), NULL);
		thread = thread->next;
		index++;
	}
	return (true);
}

bool	init_thread(t_root *root, t_input *input)
{
	int			index;
	t_thread	*head;
	t_thread	*new;

	index = 0;
	head = NULL;
	while (index < input->number_philos)
	{
		new = new_thread(head, input, index + 1);
		if (malloc_error(new))
			return (free(root->input), false);
		if (index == 0)
			head = new;
		add_back_thread(head, new);
		new = NULL;
		index++;
	}
	if (!set_start_time(head))
		return (free(root->input), false);
	if (!create_thread(head, input))
		return (free(root->input), false);
	root->thread = head;
	return (true);
}
