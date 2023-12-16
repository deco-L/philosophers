/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/16 14:56:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

static bool	take_fork(t_philo *philo, pthread_mutex_t *another)
{
	while (true)
	{
		if (check_died(philo))
			return (false);
		if (!pthread_mutex_lock(philo->fork) && \
					!pthread_mutex_lock(another))
			break ;
		pthread_mutex_unlock(philo->fork);
		pthread_mutex_unlock(another);
	}
	printf("%lld %d %s", get_time(), philo->id, TAKE);
	philo->mealtime = get_time();
	return (true);
}

bool	philo_meal(t_philo *philo)
{
	pthread_mutex_t	*another;

	if (philo->id % 2)
		another = philo->right;
	else
		another = philo->left;
	if (!take_fork(philo, another))
		return (death_notice(philo), false);
	printf("%lld %d %s", get_time(), philo->id, EAT);
	usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(another);
	return (true);
}
