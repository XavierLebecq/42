/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:32:37 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/20 17:32:50 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H

# define FUNCTIONS_H

int		buffer_len(char *str);
char	*read_dict(char *st);
int		ft_number(char *str);
int		ft_strstr(char *str, char *to_find, char *tab);
void	ft_pars(char *buffer, char *to_find);

#endif
