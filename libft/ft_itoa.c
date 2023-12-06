/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:44:45 by kojwatan          #+#    #+#             */
/*   Updated: 2023/09/28 17:56:46 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		nb *= -1;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		i;
	long	nbr;
	char	*nb_str;

	i = 1;
	nbr = n;
	if (nbr == 0)
		return (ft_strdup("0"));
	if ((n < 0))
		nbr *= -1;
	digits = count_digits(n);
	nb_str = malloc(digits + (n < 0) + 1);
	if (nb_str == NULL)
		return (NULL);
	while (nbr != 0)
	{
		nb_str[digits + (n < 0) - i] = nbr % 10 + '0';
		nbr /= 10;
		i++;
	}
	nb_str[digits + (n < 0)] = 0;
	if (n < 0)
		nb_str[0] = '-';
	return (nb_str);
}
