/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:06:55 by kojwatan          #+#    #+#             */
/*   Updated: 2023/11/21 17:54:17 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_u(unsigned int nbr)
{
	char			c;
	unsigned long	nb;

	nb = nbr;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	c = nb % 10 + '0';
	if (nb / 10 > 0)
		ft_putnbr_u(nb / 10);
	write(1, &c, 1);
}

int	print_u(unsigned int nbr)
{
	int	digit;

	digit = 0;
	ft_putnbr_u(nbr);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		digit++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		digit++;
	}
	return (digit);
}
