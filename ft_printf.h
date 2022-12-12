/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:35:37 by yoonslee          #+#    #+#             */
/*   Updated: 2022/12/12 14:41:50 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printstr(char *str);
int			ft_printnbr(int n);
int			ft_printnbr_unsigned(int n);
int			ft_printchr(int c);
int			ft_check(char c, va_list ap);
int			ft_printf(const char *str, ...);
int			ft_printhex_small(unsigned int n);
int			ft_printhex_big(unsigned int n);
int			count_hex(unsigned int n);
static int	ptr_len(unsigned long long n);
void		ptr_hexa(unsigned long long n);
int			ft_printptr(unsigned long long n);

#endif