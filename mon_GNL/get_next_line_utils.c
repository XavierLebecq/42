/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakren <krakren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:33:31 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/04 23:28:48 by krakren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

t_list  *ft_lstnew(void *content)
{
    t_list  *new_element;
    char    *content_copy;

    new_element = (t_list *)malloc(sizeof(t_list));
    if (!new_element)
        return (NULL);
    content_copy = ft_strdup(content);
    if (!content_copy)
    {
        free (new_element);
        return (NULL);
    }
    new_element->content = content_copy;
    new_element->next = NULL;
    return (new_element);
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

