/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:43:51 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/24 00:51:23 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cpy_dst;
	unsigned char	*cpy_src;

	if (!dst && !src)
		return (NULL);
	cpy_dst = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	if (cpy_dst <= cpy_src)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (len--)
			cpy_dst[len] = cpy_src[len];
	}
	return (dst);
}
