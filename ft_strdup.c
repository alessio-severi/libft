/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:03:30 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/23 15:37:57 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*copy;

	i = ft_strlen(src);
	copy = (char *) malloc(i * sizeof(char) + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, src, i + 1);
	return (copy);
}
