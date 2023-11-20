/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:49:52 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/16 21:13:11 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;

    // Vérifier si la chaîne d'entrée est NULL, et retourner NULL si c'est le cas
    if (!s)
        return (NULL);

    // Si l'indice de départ est supérieur ou égal à la longueur de la chaîne,
    // retourner une chaîne vide
    if (start >= ft_strlen(s))
        return (ft_strdup(""));

    // Si la somme de len et start dépasse la longueur de la chaîne, ajuster len
    if (len + start > (ft_strlen(s)))
        len = ft_strlen(s) - start;

    // Allouer de la mémoire pour la sous-chaîne (+1 pour le caractère nul)
    str = (char *)malloc(len + 1);

    // Vérifier si l'allocation de mémoire a échoué
    if (!str || !s)
        return (NULL);

    // Copier la sous-chaîne depuis la chaîne d'entrée dans la mémoire allouée
    ft_strlcpy(str, s + start, len + 1);

    // Retourner la sous-chaîne résultante
    return (str);
}
