/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/16 12:50:46 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# define TAKE	"has taken a fork\n"
# define EAT	"is eating\n"
# define SLEEP	"is sleeping\n"
# define THINK	"is thinking\n"
# define DIED	"died\n"
# define DEATH	1

# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>
# include "structure.h"
# include "utils.h"
# include "error.h"

bool	philo_meal(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_died(t_philo *philo);
bool	check_died(t_philo *philo);
void	death_notice(t_philo *philo);

#endif