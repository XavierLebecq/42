#include <unistd.h>

char *ft_rev(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        i++;
    }
    i--;
    while (i >= 0)
    {
        write(1, &str[i], 1);
        i--;
    }
    return (str);
}

int main()
{
    char str[] = "hello";
    ft_rev(str);
    return (0);
}