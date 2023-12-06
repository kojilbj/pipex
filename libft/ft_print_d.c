/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:06:46 by kojwatan          #+#    #+#             */
/*   Updated: 2023/11/21 17:54:01 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_d(int nbr)
{
	int		digit;
	long	nb;

	digit = 0;
	ft_putnbr_fd(nbr, 1);
	if (nbr == 0)
		return (1);
	nb = nbr;
	if (nb < 0)
	{
		nb *= -1;
		digit++;
	}
	while (nb > 0)
	{
		nb /= 10;
		digit++;
	}
	return (digit);
}
