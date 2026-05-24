/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:00:04 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/26 21:58:51 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ndl_len;

	if (!(*needle))
		return ((char *)haystack);
	ndl_len = ft_strlen(needle);
	if (!len)
		return (NULL);
	while (*haystack && len-- >= ndl_len)
	{
		if (!ft_strncmp(haystack, needle, ndl_len))
			return ((char *)(haystack));
		haystack++;
	}
	return (NULL);
}
