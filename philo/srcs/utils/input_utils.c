/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:31:22 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/29 05:27:00 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isplus(int c)
{
	return (c == '+');
}

bool	str_isdigit(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (index == 0 && ft_isplus(str[index]))
		{
			if (str[++index] == '\0')
				return (false);
			continue ;
		}
		if (!ft_isdigit(str[index]))
			return (false);
		index++;
	}
	return (true);
}
