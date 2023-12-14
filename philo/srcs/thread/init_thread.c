/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/14 17:23:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

static t_thread	*create_thread(t_root *root, t_thread *head, int id)
{
	t_thread	*new;

	(void)root;
	new = (t_thread *)ft_calloc(sizeof(t_thread), 1);
	if (malloc_error(new))
		return (destory_thread(head), NULL);
	new->prev = NULL;
	new->next = NULL;
	if (!init_mutex(new, id))
		return (destory_thread(head), NULL);
	new->thread = (pthread_t *)ft_calloc(sizeof(pthread_t), 1);
	if (malloc_error(new->thread))
		return (destory_thread(head), NULL);
	new->errorno = pthread_create(new->thread, NULL, \
						routine, (void *)new->mutex);
	if (new->errorno != 0)
		return (destory_thread(head), NULL);
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

static bool	create_fuse(t_thread *thread)
{
	t_thread	*head;
	int			*tmp_address;

	head = thread;
	tmp_address = (int *)ft_calloc(sizeof(int), 1);
	if (malloc_error(tmp_address))
		return (destory_thread(thread), false);
	head->mutex->start = tmp_address;
	thread = thread->next;
	while (thread != head)
	{
		thread->mutex->start = tmp_address;
		thread = thread->next;
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
		new = create_thread(root, head, index + 1);
		if (malloc_error(new))
			return (free(root->input), false);
		if (index == 0)
			head = new;
		add_back_thread(head, new);
		new = NULL;
		index++;
	}
	if (!create_fuse(head))
		return (free(root->input), false);
	root->thread = head;
	return (true);
}
