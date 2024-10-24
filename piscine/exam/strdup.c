#include <stdlib.h>
#include <stdio.h>


int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
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
    dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
    if (!dest)
    {
        return (NULL);
    }
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}

int main()
{
    char src[] = "bonjour";
    printf("%s", ft_strdup(src));
}