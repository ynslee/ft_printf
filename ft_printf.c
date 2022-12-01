/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:07:28 by yoonslee          #+#    #+#             */
/*   Updated: 2022/12/01 16:41:38 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char *str, va_list arg)
{
	int	length;

	length = 0;
	// c,s,p,d,o,u,x,X,%

	//hexidecimal (unsigned int type)
	//unsinged longlong for ptr datatype
	
	if (arg == 'c')
		length += va_arg(arg, int);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	arg;

	if (!str)
		return (0);
	length = 0;
	va_start(arg, str[i]);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			length = ft_check(*str, arg);
		}
		else
		{
			length += write(1, str, 1);
		}
		i++;
	}
	va_end(arg);
	return (length);
}
