/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/17 19:27:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->philo_root->print);
	printf("%lld %d %s", get_time(), philo->id, SLEEP);
	pthread_mutex_unlock(philo->philo_root->print);
	accurate_usleep(philo->time_sleep);
	return ;
}
