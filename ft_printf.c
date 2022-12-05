/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:07:28 by yoonslee          #+#    #+#             */
/*   Updated: 2022/12/05 18:37:58 by yoonslee         ###   ########.fr       */
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

// int	ft_formats(va_list args, const char format)
// {
// 	int	print_length;

// 	print_length = 0;
// 	if (format == 'c')
// 		print_length += ft_printchar(va_arg(args, int));
// 	else if (format == 's')
// 		print_length += ft_printstr(va_arg(args, char *));
// 	else if (format == 'p')
// 		print_length += ft_print_ptr(va_arg(args, unsigned long long));
// 	else if (format == 'd' || format == 'i')
// 		print_length += ft_printnbr(va_arg(args, int));
// 	else if (format == 'u')
// 		print_length += ft_print_unsigned(va_arg(args, unsigned int));
// 	else if (format == 'x' || format == 'X')
// 		print_length += ft_print_hex(va_arg(args, unsigned int), format);
// 	else if (format == '%')
// 		print_length += ft_printpercent();
// 	return (print_length);
// }


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
