/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:46:01 by kojwatan          #+#    #+#             */
/*   Updated: 2023/09/28 18:47:45 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (len == 0 && *needle != 0)
		return (0);
	if (*needle == 0)
		return ((char *)(haystack));
	while (*haystack && len > 0)
	{
		i = 0;
		while (haystack[i] == needle[i] % 128 && needle[i] && len - i > 0)
			i++;
		if (!needle[i])
			return ((char *)(haystack));
		haystack++;
		len--;
	}
	return (NULL);
}
