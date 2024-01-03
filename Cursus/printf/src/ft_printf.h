/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:28:34 by xlebecq           #+#    #+#             */
/*   Updated: 2024/01/03 16:20:49 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_threat(char c, va_list args, int *input_count);
void	ft_putchar_rtn(char c, int *input_count);
void	ft_putstr_rtn(char *s, int *input_count);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base(unsigned long long n, char *base,
			int *input_count, char c);
void	ft_putnbr(int n, int *intput_count);
void	ft_putnbr_unsigned(unsigned int n, int *input_count);

#endif
