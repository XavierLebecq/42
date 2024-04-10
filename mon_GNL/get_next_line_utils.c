/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakren <krakren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:33:31 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/10 23:48:23 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
char	*ft_strcpy(char *dest, const char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return dest;
}
*/

char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == 0)
        return ((char *)s);
    return (NULL);
}

size_t  ft_strlen(const char *s)
{
    size_t  length;

    length = 0;
    while (s[length])
        length++;
    return (length);
}

/*
char    *ft_strdup(const char *s1)
{
    char    *copy;
    size_t  i;

    i = 0;
    copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
    if (!copy)
        return (NULL);
    while (s1[i])
    {
        copy[i] = s1[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}
*/

t_list  *ft_lstnew(void *content)
{
    t_list  *new_node;
    char    *content_copy;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    content_copy = malloc(ft_strlen(content) + 1);
    if (!content_copy)
    {
        free (new_node);
        return (NULL);
    }
	ft_strlcpy(content_copy, (char *)content, ft_strlen((char *)content) + 1);
    new_node->content = content_copy;
    new_node->next = NULL;
    return (new_node);
}

void    ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list  *last;

    if (!*alst)
    {
        *alst = new;
        return ;
    }
    last = *alst;
    while (last->next)
        last = last->next;
    last->next = new;
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t  i;

    i = 0;
    if (dstsize != 0)
    {
        while (src[i] != '\0' && i < (dstsize - 1))
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    while (src[i] != '\0')
        i++;
    return (i);
}

