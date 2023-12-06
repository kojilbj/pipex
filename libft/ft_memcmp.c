/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:45:15 by kojwatan          #+#    #+#             */
/*   Updated: 2023/09/28 18:38:02 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dst;

	src = (unsigned char *)s1;
	dst = (unsigned char *)s2;
	while (n > 0)
	{
		if (*dst != *src)
			return (*src - *dst);
		src++;
		dst++;
		n--;
	}
	return (0);
}
