/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/17 19:34:54 by csakamot         ###   ########.fr       */
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

bool	init_thread(t_root *root, t_input *input, t_philo_root *philo_root);
bool	init_philo(t_thread *thread, t_input *input, \
										t_philo_root *philo_root, int id);
bool	init_philo_root(t_root *root);
void	*routine(void *arg);
void	wait_thread(t_input *input, t_thread *thread);
void	destory_philo_root(t_philo_root *philo_root);
void	destory_mutex(t_philo *philo);
void	destory_thread(t_thread *head, t_philo_root *philo_root);

#endif