
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;

    while (s1[i] && s2[i])
    {
        if (s1[i] == s2[i])
        {
            i++;
        }
        else
        return (s1[i] - s2[i]); 
    }
}

int main()
{
    char str[] = "a";
    char str1[] = "b";
    printf("%d", ft_strcmp(str, str1));
}