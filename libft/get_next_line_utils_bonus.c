/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:42:41 by watanabekoj       #+#    #+#             */
/*   Updated: 2023/11/21 17:47:00 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	length;

// 	length = 0;
// 	if (s == NULL || s[length] == 0)
// 		return (0);
// 	while (s[length])
// 		length++;
// 	return (length);
// }

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str_joined;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		str_joined = malloc(ft_strlen(s2) + 1);
	else
		str_joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	while (str_joined != NULL && s1 && s1[i])
	{
		str_joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (str_joined != NULL && s2 && s2[i])
	{
		str_joined[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	if (str_joined != NULL)
		str_joined[ft_strlen(s1) + i] = 0;
	free((void *)s1);
	return (str_joined);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	*str;
// 	unsigned char	i;

// 	i = c;
// 	str = (unsigned char *)s;
// 	while (str && *str)
// 	{
// 		if (*str == i)
// 			return ((char *)(str));
// 		str++;
// 	}
// 	if (c == 0)
// 		return ((char *)(str));
// 	return (NULL);
// }

char	*linecpy(char *str)
{
	size_t	length;
	size_t	i;
	char	*line;

	if (str == NULL)
		return (NULL);
	length = 0;
	while (str[length] != '\n' && str[length] && str[length] != 26)
		length++;
	line = malloc(length + 2);
	i = 0;
	while (line != NULL && length + 1 > i)
	{
		line[i] = str[i];
		i++;
	}
	if (line != NULL)
		line[i] = 0;
	free(str);
	return (line);
}

char	*save_to_buff(char *src)
{
	size_t	i;
	size_t	k;
	char	*dest;

	if (src == NULL || *src == 0)
		return (NULL);
	i = 0;
	k = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == 0 || src[i + 1] == 0)
		return (NULL);
	dest = (char *)malloc(ft_strlen((char *)&src[++i]) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i])
		dest[k++] = src[i++];
	dest[k] = 0;
	return (dest);
}
