/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:07:28 by yoonslee          #+#    #+#             */
/*   Updated: 2022/12/05 18:43:51 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_check(char c, va_list ap)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_printchr(va_arg(ap, int));
	else if (c == 's')
		length += ft_printstr(va_arg(ap, char *));
	else if (c == 'p') //the void *pointer argument is printed in hexadecimal && needs to be unsigned long long
		length += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i') // int argument is convereted to signed decimal notation
		length += ft_printnbr(va_arg(ap, int));
	else if (c == 'u')//unsigned int argument is converted to unsigned decimal
		length += ft_printnbr_unsigned(va_arg(ap, unsigned long));
	else if (c == 'x')//unsigned int argument is converted to unsigned hexadecimal
		length += ;
	else if (c == 'X')//unsigned int argument is converted to unsigned hexadecimal
		length += ;
	else if (c == '%')
		length += ft_printchr('%');
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	ap;

	if (!str)
		return (0);
	length = 0;
	va_start(ap, str[i]);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			length += ft_check(str[i], ap);
		}
		else
			length += ft_printchar(str[i]);
		i++;
	}
	va_end(ap);
	return (length);
}
