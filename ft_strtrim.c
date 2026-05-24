/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:41:38 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/26 18:24:09 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_minus(size_t len, size_t shift)
{
	if (shift != 1)
		return (shift - len);
	return (len - shift);
}

static char const	*ft_find_match(char const *s1, char const *set,
	size_t len, size_t shift)
{
	size_t	j;
	size_t	i;
	int		trovato;

	while (len)
	{
		j = 0;
		trovato = 0;
		while (set[j])
		{
			i = ft_minus(len, shift);
			if (set[j] == s1[i])
			{
				len--;
				trovato = 1;
				break ;
			}
			j++;
		}
		if (!trovato)
			return (&s1[i]);
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	if (!(*set))
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	start = ft_find_match(s1, set, len, len);
	if (!start)
		return ((char *) ft_calloc(1, sizeof(char)));
	end = ft_find_match(s1, set, len, 1);
	return (ft_substr(s1, (unsigned int)(start - s1),
		(size_t)(end - start + 1)));
}
