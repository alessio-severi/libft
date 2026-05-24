/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:51:11 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/26 20:48:23 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_strs(char const *s, char c)
{
	size_t	count_strs;
	int		flag_str;

	count_strs = 0;
	flag_str = 0;
	while (*s)
	{
		if (*s == c)
			flag_str = 0;
		else if (!flag_str)
		{
			flag_str = 1;
			count_strs++;
		}
		s++;
	}
	return (count_strs);
}

static size_t	ft_strlen_delimiter(char const **s, char c)
{
	size_t	str_len;

	str_len = 0;
	while (**s && **s == c)
		(*s)++;
	while (**s && **s != c)
	{
		(*s)++;
		str_len++;
	}
	return (str_len);
}

static int	ft_check_free_all(char **start, char **result)
{
	int	i;

	if (*result)
		return (0);
	i = 0;
	while (start != result)
	{
		free(*start);
		start++;
		i++;
	}
	free(start - i);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	count_strs;
	size_t	str_len;
	char	**result;
	char	**start;

	if (!s)
		return (NULL);
	count_strs = ft_count_strs(s, c);
	result = (char **) malloc(sizeof(char *) * (count_strs + 1));
	if (!result)
		return (NULL);
	start = result;
	while (*s)
	{
		str_len = ft_strlen_delimiter(&s, c);
		if (!str_len)
			break ;
		*result = (char *) ft_calloc(str_len + 1, sizeof(char));
		if (ft_check_free_all(start, result))
			return (NULL);
		ft_strlcpy(*result, s - str_len, str_len + 1);
		result++;
	}
	*result = NULL;
	return (result - count_strs);
}
