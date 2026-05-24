/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:26:59 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/24 17:50:11 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb_len(long number, size_t *negative_flag)
{
	size_t	nb_len;

	nb_len = 0;
	*negative_flag = 0;
	if (!number)
		nb_len++;
	else if (number < 0)
	{
		*negative_flag = 1;
		number = -number;
	}
	while (number)
	{
		number /= 10;
		nb_len++;
	}
	return (nb_len);
}

static int	ft_add_number(char *data, long number)
{
	int	pos;

	pos = 0;
	if (number > 9)
		pos = ft_add_number(data, number / 10);
	data[pos] = number % 10 + '0';
	return (pos + 1);
}

char	*ft_itoa(int n)
{
	size_t	negative_flag;
	size_t	nb_len;
	long	number;
	char	*data;

	negative_flag = 0;
	number = n;
	nb_len = ft_nb_len(number, &negative_flag);
	data = (char *) ft_calloc(nb_len + negative_flag + 1, sizeof(char));
	if (!data)
		return (NULL);
	if (negative_flag)
	{
		*data++ = '-';
		number = -number;
	}
	data[ft_add_number(data, number)] = 0;
	return (data - negative_flag);
}
