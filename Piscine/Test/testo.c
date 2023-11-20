#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char *ft_strrev(char *str)
{
    int i;
    int len;
    int temp;

    i = 0;
    len = ft_strlen(str) - 1;

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

char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

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

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
        i++;
    return (s1[1] - s2[i]);
}
void ft_putnbr(int nbr)
{
    if (nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
    }
    if (nbr < 10)
        ft_putchar(nbr + 48); 
    if (nbr > 9)
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

    while(str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
        i++;
    if (str[i] == '-')
    {
        sign -= 1;
        i++;
    }
    else if(str[i] == '+')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result * sign);

}

char *ft_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] +32;
        }
        i++;
    }
}

int main()
{
    ft_putnbr(-1);
}
