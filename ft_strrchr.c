/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:17:59 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/24 00:32:56 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*start_address;

	start_address = s;
	while (*s)
		s++;
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (s == start_address)
			break ;
		s--;
	}
	return (NULL);
}
