/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:41:43 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/07 11:04:34 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long nb)
{
	char	str[12];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (nb == 0)
		str[i++] = '0';
	if (nb < 0)
	{
		ft_putchar('-');
		len++;
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	len += i;
	while (i > 0)
		ft_putchar(str[--i]);
	return (len);
}

int	ft_putnbr_hex(unsigned long nb, char spec)
{
	char	*base;
	char	str[16];
	int		i;
	int		len;

	i = 0;
	base = "0123456789abcdef";
	if (spec == 'X')
		base = "0123456789ABCDEF";
	if (nb == 0)
		return (write(1, "0", 1));
	while (nb > 0)
	{
		str[i++] = base[nb % 16];
		nb /= 16;
	}
	len = i;
	while (--i >= 0)
		ft_putchar(str[i]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	return (len + ft_putnbr_hex((unsigned long)ptr, 'x'));
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}
