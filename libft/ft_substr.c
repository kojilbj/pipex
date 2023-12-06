/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:46:08 by kojwatan          #+#    #+#             */
/*   Updated: 2023/10/01 14:24:15 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*substr;
	size_t			i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen(&s[start]))
		substr = malloc(len + 1);
	else
		substr = malloc(ft_strlen(&s[start]) + 1);
	if (substr == NULL)
		return (NULL);
	while (i < len)
	{
		if (s[start])
			substr[i++] = s[start++];
		else
			break ;
	}
	substr[i] = 0;
	return ((char *)(substr));
}
