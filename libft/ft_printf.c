/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:07:02 by kojwatan          #+#    #+#             */
/*   Updated: 2023/11/21 17:54:35 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	decide_fomat(char c, va_list *ap)
{
	if (c == 'c')
		return (print_c(va_arg(*ap, int)));
	if (c == 's')
		return (print_s(va_arg(*ap, char *)));
	if (c == 'p')
		return (print_p(va_arg(*ap, void *)));
	if (c == 'd' || c == 'i')
		return (print_d(va_arg(*ap, int)));
	if (c == 'u')
		return (print_u(va_arg(*ap, unsigned int)));
	if (c == 'x')
		return (print_x(va_arg(*ap, int)));
	if (c == 'X')
		return (print_x_cap(va_arg(*ap, int)));
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	ap;

	va_start(ap, str);
	length = 0;
	while (*str)
	{
		if (*str == '%')
			length += decide_fomat(*(++str), &ap);
		else
		{
			ft_putchar_fd(*str, 1);
			length++;
		}
		str++;
	}
	va_end(ap);
	return (length);
}
