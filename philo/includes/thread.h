/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/17 14:38:28 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>
# include "routine.h"
# include "structure.h"
# include "utils.h"
# include "error.h"

bool	init_thread(t_root *root, t_input *input);
bool	init_philo(t_thread *thread, t_input *input, int id);
void	*routine(void *arg);
void	wait_thread(t_input *input, t_thread *thread);
void	destory_thread(t_thread *head);

#endif