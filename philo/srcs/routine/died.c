/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/17 19:28:53 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

void	philo_died(t_philo *philo)
{
	pthread_mutex_lock(philo->philo_root->print);
	printf("%lld %d %s", get_time(), philo->id, DIED);
	pthread_mutex_unlock(philo->philo_root->print);
	return ;
}

bool	check_died(t_philo *philo)
{
	long	cool_time;

	cool_time = get_time() - philo->mealtime;
	if (cool_time > philo->time_die)
		return (philo_died(philo), true);
	return (false);
}
