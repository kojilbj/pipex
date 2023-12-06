/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:45:50 by kojwatan          #+#    #+#             */
/*   Updated: 2023/09/28 18:46:06 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	space_left;
	size_t	i;

	if (dstsize == 0 && dest == 0)
		return (ft_strlen((char *)src));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	space_left = dstsize - dest_len - 1;
	i = 0;
	while (src[i] != '\0' && i < space_left)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (src_len > space_left)
		return (dest_len + src_len);
	else
		return (dest_len + i);
}
