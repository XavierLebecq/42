#include <unistd.h>
#include <stdio.h>

char *ft_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
    return (str);
}


void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strcpy(char *dest, char *src)
{
    int i;
    
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while ((s1[i] == s2[i]) && (s1[i] != '\0' || s2[i] != '\0'))
        i++;
    return (s1[i] - s2[i]);
}

void ft_putnbr(int nbr)
{
    if (nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr =  -nbr;
    }
    if (nbr < 10)
    {
        ft_putchar(nbr + 48);
    }
    if (nbr >9)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}
int ft_atoi(char *str)
{
    int i;
    int sign;
    int result;
    
    i = 0;
    sign = 1;
    result = 0;

    while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    if (str[i] == '+')
    {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result * sign);
    
}

char *ft_strcapitalize(char *str)
{
    int i;

    i = 0;
    ft_strlowcase(str);
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        str[i] -= 32;
    }

    while (str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            if (str[i-1] == ' ')
                str[i] -= 32;
        }
        i++;
    }
    return (str);   
}

int main()
{
    char dest[20];
    char str[] = " Hello     comment ca va\n";
    char str1[] = "Donjour";
    char atoi[] = "-+42";

    //ft_putchar('S');
    //ft_putchar('\n');
    //ft_putstr(str);
    //printf ("%d\n", ft_strlen(str));
    //printf ("%s", ft_strcpy(dest, str));
    //printf ("%d\n", ft_strcmp(str, str1));
    //ft_putnbr(-2147483648);
    //ft_putchar('\n');
    //printf ("%d\n", ft_atoi(atoi));
    printf ("%s", ft_strcapitalize(str));

    return(0);

}