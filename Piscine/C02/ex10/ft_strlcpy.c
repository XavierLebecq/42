/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:14:11 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/22 04:16:07 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char*str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return(i);
}
unsigned int ft_strlpy