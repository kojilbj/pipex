/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:45:47 by kojwatan          #+#    #+#             */
/*   Updated: 2023/09/28 18:45:54 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str_joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str_joined == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str_joined[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	str_joined[ft_strlen(s1) + i] = 0;
	return (str_joined);
}
