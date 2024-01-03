/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:28:34 by xlebecq           #+#    #+#             */
/*   Updated: 2024/01/01 23:19:06 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stlib.h>
#include <stdarg.h>
#include <unistd.h>

#define UnsignedINT_MAX 4294967295
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int	ft_printf(const char *input, ...);
char	*ft_strdup(const char *s);
void	ft_putchar_rtn(char c, int *input_count);
void	ft_putstr_rtn(char *s, int *input_count);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base(unsigned long long n, char *base, int *input_count, char c)
void	ft_putnbr(int n, int *intput_count)
void	






#endif

