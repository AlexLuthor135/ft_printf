/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:03:34 by alappas           #+#    #+#             */
/*   Updated: 2024/04/14 00:40:40 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(uintptr_t v, int base)

{
	int	len;

	len = 0;
	while (v != 0)
	{
		len++;
		v /= base;
	}
	return (len);
}

int	ft_putchar_fd(char c, int fd)
{
	return (write (fd, &c, 1));
}

int	ft_format(va_list args, char f)

{
	int	value;

	value = 0;
	if (f == 'c')
		value += ft_putchar_fd(va_arg(args, int), 1);
	else if (f == 's')
		value += ft_printf_s(va_arg(args, char *));
	else if (f == 'p')
		value += ft_printf_p(va_arg(args, unsigned long long));
	else if (f == 'd' || f == 'i')
		value += ft_printf_d(va_arg(args, int));
	else if (f == 'u')
		value += ft_printf_undec(va_arg(args, unsigned int));
	else if (f == 'x')
		value += ft_printf_x(va_arg(args, unsigned int), 0);
	else if (f == 'X')
		value += ft_printf_x(va_arg(args, unsigned int), 32);
	else if (f == '%')
		value += ft_putchar_fd('%', 1);
	return (value);
}

int	ft_printf(const char *s, ...)

{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_format(args, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
