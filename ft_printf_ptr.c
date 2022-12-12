/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:33:42 by yoonslee          #+#    #+#             */
/*   Updated: 2022/12/12 14:41:06 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ptr_hexa(unsigned long long n)
{
	int	temp;

	if (n >= 16)
	{
		ft_printhex_big(n / 16);
		ft_printhex_bif(n % 16);
	}
	if (n >= 10 && n < 16)
		temp = n - 10 + 'a';
	if (n < 10)
		temp = n - 10 + '0';
	ft_printchr(temp);
}

int	ft_printptr(unsigned long long n)
{
	ft_putchar_chr('0');
	ft_putchar_chr('x');
	ft_hexa_deci_ptr(n);
	return (ptr_len(n));
}
