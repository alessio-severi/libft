/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:24:35 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/23 15:16:53 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sgn;
	long	number;

	sgn = 1;
	number = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sgn *= -1;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str++ - '0';
		if (sgn > 0 && (int) number != number)
			return (-1);
		else if (sgn < 0 && (int) -number != -number)
			return (0);
	}
	return ((int)(number * sgn));
}
