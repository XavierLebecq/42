#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>








char *ft_strdup(char *src)
{
    int i;
    char *dest;

    i = 0;
    dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return (dest);
    free (dest);
}





}

char *ft_strcapitalize(char *str)
{
    int i;
    int j;

    i = 0;
    j = 1;
    ft_strlowcase(str);
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (j == 1)
            {
                str[i] = str[i]- 32;
                j = 0;
            }
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            j = 0;
        }
        else
        {
            j = 1;
        }
        i++;
    }
    return (str);
}
int main()
{
    int i;

    i = 1;

    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            write(1, "fizzbuzz", 8);
        }
        else if (i % 3 == 0)
        {
            write(1, "fizz", 4);
        }
        else if (i % 5 == 0)
        {
            write(1, "buzz", 4);
        }
        else
        {
            ft_putnbr(i);
        }
        ft_putchar('\n');
        i++;
        
        
    }
    char str[] = "12";
    char src[] = "ecole42GOOD";
    char dest[3];
   // printf ("%d ATOI\n", ft_atoi(str));
    //printf ("%s STRDUP\n", ft_strdup(src));
   // printf ("%d STRCMP\n", ft_strcmp(src, str));
   // printf ("%s CAPITALIZE\n", ft_strcapitalize(src));
    printf ("%s FTIS", ft_is(dest, src));
    return (0);
}