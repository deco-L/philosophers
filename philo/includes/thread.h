/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/14 17:24:52 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# define START 1

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include "structure.h"
# include "utils.h"
# include "error.h"

bool	init_thread(t_root *root, t_input *input);
bool	init_mutex(t_thread *thread, int id);
bool	start_thread(t_thread *thread);
void	*routine(void *arg);
void	wait_thread(t_input *input, t_thread *thread);
void	destory_thread(t_thread *head);

#endif