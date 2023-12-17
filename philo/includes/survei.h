/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   survei.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/12/17 14:41:18 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SURVEI_H
# define SURVEI_H

# include <stdbool.h>
# include "structure.h"
# include "thread.h"
# include "input.h"
# include "routine.h"
# include "utils.h"

bool	surveillance(t_input *input, t_thread *thread);

#endif