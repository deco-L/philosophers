/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/15 14:46:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <pthread.h>

typedef struct s_mutex
{
	int				id;
	long			fire;
	pthread_mutex_t	*fork;
}				t_mutex;

typedef struct s_thread
{
	pthread_t		*thread;
	t_mutex			*mutex;
	struct s_thread	*prev;
	struct s_thread	*next;
}				t_thread;

typedef struct s_input
{
	int	number_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	count_task;
}				t_input;

typedef struct s_root
{
	int			start;
	t_input		*input;
	t_thread	*thread;
}				t_root;

#endif