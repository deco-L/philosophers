/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/16 12:26:30 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				status;
	long			fire;
	long			mealtime;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				count_task;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}				t_philo;

typedef struct s_thread
{
	pthread_t		*thread;
	t_philo			*philo;
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