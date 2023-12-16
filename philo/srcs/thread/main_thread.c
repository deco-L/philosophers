/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/16 15:03:23 by csakamot         ###   ########.fr       */
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
	int		count;
	t_philo	*philo;

	count = 0;
	philo = arg;
	yooi_don(philo->fire);
	philo->mealtime = get_time();
	while (count < philo->count_task || philo->count_task == 0)
	{
		if (!philo_meal(philo))
			break ;
		philo_sleep(philo);
		philo_think(philo);
		if (philo->count_task != 0)
			count++;
	}
	return (NULL);
}
