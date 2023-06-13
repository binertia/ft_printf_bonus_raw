/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksongchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:24:34 by ksongchu          #+#    #+#             */
/*   Updated: 2023/06/14 05:57:51 by ksongchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define HEXA "0123456789abcdef"

size_t	ft_putnbr_custom(long n, int lowercase, int base)
{
	char	*hexa_digits;
	size_t	len;

	len = 0;
	hexa_digits = HEXA;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len++;
	}
	if (n >= base)
		len += ft_putnbr_custom(n / base, lowercase, base);
	if (lowercase || (n % base < 10))
		ft_putchar(hexa_digits[n % base]);
	else
		ft_putchar(ft_lowertoupper(hexa_digits[n % base]));
	len += 1;
	return (len);
}

size_t	ft_putnbr_p(unsigned long n)
{
	char	*hexa_digits;
	size_t	len;

	len = 0;
	hexa_digits = HEXA;
	if (n >= 16)
		len += ft_putnbr_p(n / 16);
	ft_putchar(hexa_digits[n % 16]);
	len += 1;
	return (len);
}

size_t	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (write(1, s, ft_strlen(s)));
}

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
