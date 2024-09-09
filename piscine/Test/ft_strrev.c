#include <stdio.h>


int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char *ft_strrev(char *str)
{
    int i;
    int len;
    int temp;

    i = 0;
    len = ft_strlen(str) - 1;
    temp = 0;
    while (i < len)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }
    return (str);
}


int main()
{
    char str[] = "hello";
    printf("%s", ft_strrev(str));
    return(0);
}