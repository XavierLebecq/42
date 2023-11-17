/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:30:56 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/16 21:46:35 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*str;

	i = 0;
	k = 0;
	if (!s || !set) // Ajout d'une vérification pour les pointeurs NULL
		return (NULL);
	while (s[i] && ft_strchr(set, s[i])) // Utilisation de ft_strchr pour vérifier les caractères à supprimer
		i++;
	if (s[i] == '\0')
		return (ft_strdup("")); // Utilisation de ft_strdup pour éviter les fuites de mémoire
	j = ft_strlen(s) - 1;
	while (j > i && ft_strchr(set, s[j])) // Utilisation de ft_strchr et ajustement des conditions
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 2)); // Correction de la taille allouée pour inclure le caractère nul
	if (str == NULL)
		return (NULL);
	while (k < j - i + 1)
	{
		str[k] = s[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}