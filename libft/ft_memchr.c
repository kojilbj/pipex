/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:45:12 by kojwatan          #+#    #+#             */
/*   Updated: 2023/10/01 14:23:40 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	i;

	i = (unsigned char)c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == i)
			return (str);
		n--;
		str++;
	}
	return (0);
}
