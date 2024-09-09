#include <stdio.h>

char *ft_cap(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        while(str[i] == ' ')
        i++;
    }
    if (str[i] != ' ')
    {
        str[i] = str[i] + 32;
    }
    while (str[i])
    i++;
    return (str);
}

int main()
{
    char str[] = " bonjour allo";
    printf("%s", ft_cap(str));
}