/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 01:24:45 by aseveri           #+#    #+#             */
/*   Updated: 2026/05/19 13:00:43 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;
	size_t	memspz;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size > (size_t)-1 / count)
		return (NULL);
	memspz = count * size;
	data = malloc(memspz);
	if (!data)
		return (NULL);
	ft_bzero(data, memspz);
	return (data);
}
