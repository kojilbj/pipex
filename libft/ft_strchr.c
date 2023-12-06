/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:45:40 by kojwatan          #+#    #+#             */
/*   Updated: 2023/11/21 17:46:48 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	*str;
// 	unsigned char	i;

// 	i = c;
// 	str = (unsigned char *)s;
// 	while (*str)
// 	{
// 		if (*str == i)
// 			return ((char *)(str));
// 		str++;
// 	}
// 	if (c == 0)
// 		return ((char *)(str));
// 	return (0);
// }
char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	i;

	i = c;
	str = (unsigned char *)s;
	while (str && *str)
	{
		if (*str == i)
			return ((char *)(str));
		str++;
	}
	if (c == 0)
		return ((char *)(str));
	return (NULL);
}