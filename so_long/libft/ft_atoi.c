/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:23:32 by ahkalama          #+#    #+#             */
/*   Updated: 2023/02/18 14:23:35 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		y;
	long	rslt;

	y = 1;
	rslt = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			y = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rslt = y * (*str - '0') + (rslt * 10);
		if (rslt > 21474483647)
			return (-1);
		if (rslt < -2147483648)
			return (0);
		str++;
	}
	return (rslt);
}
