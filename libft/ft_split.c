/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:45:37 by kojwatan          #+#    #+#             */
/*   Updated: 2023/09/28 20:22:52 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] == c)
		i++;
	count = s[i] != 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			i++;
			count++;
		}
	}
	return (count);
}

static void	free_all(char **strs, int i)
{
	while (i > 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs[i]);
}

static char	**split_alloc(char **strs, char *str, char c, int end)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < end)
	{
		count = 0;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			str++;
			count++;
		}
		strs[i] = (char *)malloc(count + 1);
		if (strs[i] == NULL)
		{
			free_all(strs, i);
			return (NULL);
		}
		i++;
	}
	strs[i] = 0;
	return (strs);
}

char	**split_help(char **strs, char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strs[i])
	{
		while (*s == c)
			s++;
		if (*s == 0)
			break ;
		while (*s != c && *s)
			strs[i][j++] = *(s++);
		strs[i++][j] = 0;
		j = 0;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (s == NULL)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	strs = split_alloc(strs, (char *)s, c, count_words(s, c));
	if (strs == NULL)
		return (NULL);
	return (split_help(strs, (char *)s, c));
}
