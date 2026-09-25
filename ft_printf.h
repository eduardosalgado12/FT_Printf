/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:55:28 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/05 15:15:12 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *fmt, ...);
int	ft_putchar(char c);
int	ft_putnbr(long nb);
int	ft_putnbr_hex(unsigned long nb, char spec);
int	ft_putptr(void *ptr);
int	ft_putstr(char *str);

#endif