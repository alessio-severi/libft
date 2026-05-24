/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:15:24 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/25 22:42:38 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
	size_t len)
{
	char	*result;
	size_t	result_size;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return ((char *)ft_calloc(1, sizeof(char)));
	else
	{
		if (str_len - start > len)
			result_size = len + 1;
		else
			result_size = str_len - start + 1;
	}
	result = (char *) ft_calloc(result_size, sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, result_size);
	return (result);
}
