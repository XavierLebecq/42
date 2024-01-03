/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:13:32 by xlebecq           #+#    #+#             */
/*   Updated: 2024/01/01 23:18:51 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#included "ft_printf.h"


int	ft_threat(char c, va_list args, int *input_count)
{
	if (c == 'c')
		ft_putchar_rtn((char)va_arg(args, int), input_count);
	else if (c == 's')
		ft_putstr_rtn((char *)va_arg(args, char *), input_count);
	else if (c == 'p')
		ft_putnbr_base((unsigned long long)va_args(args, unsigned long long), "0123456789abcdef", input_count, c);
	e

		ft_putnbr((int)va_args(args, int), input_count);
	else if (c == 'u')
		ft_putnbr_unsigned((unsigned int)va_args(args, unsigned int), input_count);
}
int	ft_printf(const char *input, ...)
{
	char	*input_cpy;
	int	input_count;
	va_list	args;
	size_t	i;

	input_cpy = ft_strdup(input);
	input_count = 0;
	va_start(args, input);
	i = 0;
	while (input_cpy[i]
	{
		if (input_cpy[i] == '%')
		{
			ft_threat(input_cpy[i + 1], args, input_count);
			i++;
		}
		else
			ft_putchar(input_cpy[i], &input_count);
		i++;
	}
	va_end(args);
	free(input_cpy);
	return (input_count);
}
			
