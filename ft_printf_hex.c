/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:40:14 by yoonslee          #+#    #+#             */
/*   Updated: 2022/12/12 14:32:29 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_printhex_big(unsigned int n)
{
	int	temp;
	int	count;

	count = count_hex(n);
	if (n >= 16)
	{
		ft_printhex_big(n / 16);
		ft_printhex_bif(n % 16);
	}
	if (n >= 10 && n < 16)
		temp = n - 10 + 'A';
	if (n < 10)
		temp = n - 10 + '0';
	ft_printchr(temp);
	return (count);
}

int	ft_printhex_small(unsigned int n)
{
	int	temp;
	int	count;

	count = count_hex(n);
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
	return (count);
}
