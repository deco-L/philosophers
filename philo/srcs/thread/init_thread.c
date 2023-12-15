/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/15 13:43:12 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

static bool	set_start_time(t_thread *thread)
{
	
	return (true);
}

static t_thread	*create_thread(t_thread *head, int id)
{
	t_thread	*new;

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
	if (pthread_create(new->thread, NULL, routine, (void *)new->mutex) != 0)
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

bool	init_thread(t_root *root, t_input *input)
{
	int			index;
	t_thread	*head;
	t_thread	*new;

	index = 0;
	head = NULL;
	while (index < input->number_philos)
	{
		new = create_thread(head, index + 1);
		if (malloc_error(new))
			return (free(root->input), false);
		if (index == 0)
			head = new;
		add_back_thread(head, new);
		new = NULL;
		index++;
	}
	set_start_time(head);
	root->thread = head;
	return (true);
}
