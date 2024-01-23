/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/22 17:34:00 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/thread.h"

static void	yooi_don(long long fire)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	while (fire > tv.tv_sec)
		gettimeofday(&tv, NULL);
	return ;
}

void	*routine(void *arg)
{
	int			count;
	t_philo		*philo;

	count = 0;
	philo = arg;
	yooi_don(philo->fire);
	if (philo->id % 2)
		accurate_usleep(100);
	philo->mealtime = get_time();
	while (count < philo->count_task || philo->count_task == 0)
	{
		philo_meal(philo, &count);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
