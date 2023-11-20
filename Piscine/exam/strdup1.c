#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        i++;
    }
    return(i);
}

char *ft_strdup(char *src)
{
    int i;
    char *dest;
    
    i = 0;
    dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);

    
}

int main()
{
    char src[] = "bonjour";
    printf ("%s", ft_strdup(src));
}