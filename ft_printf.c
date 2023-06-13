/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksongchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:09:12 by ksongchu          #+#    #+#             */
/*   Updated: 2023/06/14 05:11:28 by ksongchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_indicate(char c, va_list *a_list)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar((char)va_arg(*a_list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*a_list, char *)));
	else if (c == 'd')
		return (ft_putnbr_custom(va_arg(*a_list, int), 1, 10));
	else if (c == 'i')
		return (ft_putnbr_custom(va_arg(*a_list, int), 1, 10));
	else if (c == 'u')
		return (ft_putnbr_custom(va_arg(*a_list, unsigned int), 1, 10));
	else if (c == 'x')
		return (ft_putnbr_custom(va_arg(*a_list, unsigned int), 1, 16));
	else if (c == 'X')
		return (ft_putnbr_custom(va_arg(*a_list, unsigned int), 0, 16));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_putnbr_p(va_arg(*a_list, unsigned long)) + 2);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	a_list;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	va_start(a_list, str);
	while (str[i])
	{
		if (str[i] == '\\')
			len += ft_putchar('\\');
		else if (str[i] == '%')
		{
			len += ft_indicate(str[i + 1], &a_list);
			i += 1;
		}
		else
			len += ft_putchar(str[i]);
		i += 1;
	}
	va_end(a_list);
	return ((int)len);
}
