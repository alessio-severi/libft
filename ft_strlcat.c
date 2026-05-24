/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 03:32:48 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/23 14:17:18 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	char	*start_dst;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len])
		dst_len++;
	if (dst_len < dstsize)
	{
		start_dst = dst;
		dst += dst_len;
		while (*src && (size_t)(dst - start_dst) < dstsize - 1)
			*dst++ = *src++;
		*dst = 0;
		return (dst_len + src_len);
	}
	return (dstsize + src_len);
}
