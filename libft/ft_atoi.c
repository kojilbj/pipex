/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:44:06 by kojwatan          #+#    #+#             */
/*   Updated: 2023/09/28 17:51:34 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_strtol(const char *str, int sign)
{
	long	result;
	long	tmp;

	result = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		tmp = result;
		result = result * 10 + *str - '0';
		if (result < tmp)
		{
			if (sign == -1)
				return (LONG_MIN);
			else
				return (LONG_MAX);
		}
		str++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		sign_fg;

	sign_fg = 0;
	result = 0;
	sign = 1;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		if (sign_fg == 1)
			return (result);
		sign_fg = 1;
		str++;
	}
	return ((int)(ft_strtol(str, sign)));
}
