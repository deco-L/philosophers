/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/17 18:08:30 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

static bool	take_fork(t_philo *philo, pthread_mutex_t *another)
{
	if (philo->id % 2)
		accurate_usleep(100);
	pthread_mutex_lock(another);
	pthread_mutex_lock(philo->fork);
	printf("%lld %d %s", get_time(), philo->id, TAKE);
	philo->mealtime = get_time();
	return (true);
}

bool	philo_meal(t_philo *philo, int *count)
{
	pthread_mutex_t	*another;

	another = philo->right;
	if (philo->fork == another)
		return (true);
	take_fork(philo, another);
	printf("%lld %d %s", get_time(), philo->id, EAT);
	accurate_usleep(philo->time_eat);
	if (philo->count_task != 0)
		*count = *count + 1;
	if (philo->count_task != 0 && *count == philo->count_task)
		philo->status = END;
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(another);
	return (true);
}
