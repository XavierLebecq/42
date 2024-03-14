/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:32:47 by xlebecq           #+#    #+#             */
/*   Updated: 2024/01/30 14:32:32 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



static int	ft_read(char **p_buffer, int fd)
{
	while (ft_check(

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024 ))
		return (NULL);
	if (!ft_check(buffer) && !ft_read(&buffer, fd)
			return (NULL);
}
