/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:29:17 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/07 11:18:45 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(char spec, va_list args)
{
	int	c;

	c = 0;
	if (spec == 'c')
		c += ft_putchar(va_arg(args, int));
	else if (spec == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (spec == 'a')
		c += ft_putstr("something");
	else if (spec == 'd' || spec == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (spec == 'u')
		c += ft_putnbr(va_arg(args, unsigned int));
	else if (spec == 'x' || spec == 'X')
		c += ft_putnbr_hex(va_arg(args, unsigned int), spec);
	else if (spec == 'p')
		c += ft_putptr(va_arg(args, void *));
	else if (spec == '%')
		c += write(1, "%", 1);
	return (c);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		c;

	c = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			fmt++;
			c += ft_conversion(*fmt, args);
		}
		else
			c += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (c);
}
