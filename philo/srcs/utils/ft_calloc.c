/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:04:09 by sakamoto          #+#    #+#             */
/*   Updated: 2023/12/02 18:59:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*c;

	if (nmemb == 0 || size == 0)
	{
		c = (void *)malloc(1);
		c[0] = 0;
		return ((void *)c);
	}
	if (size != 0 && nmemb > (size_t)SIZE_MAX / size)
		return (NULL);
	c = (void *)malloc(nmemb * size);
	if (c == NULL)
		return (NULL);
	ft_bzero(c, nmemb * size);
	return ((void *)c);
}
