
#include <unistd.h>

int ft_ct2(char *str, char c)
{
    int i;
    i = 0;
    while (str[i])
    {
        if(str[i] == c)
        {
            return(0);
        }
        i++;
    }
    return (1);
}

int ft_ct1(char *str, char c, int p)
{
    int i;
    i = 0;
    while (i < p)
    {
        if(str[i] == c)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int ft_un(char *str, char *str1)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(ft_ct1(str, str[i], i) == 1)
        {
            write(1, &str[i], 1);
        }
        i++;
    }
    i = 0;
    while (str1[i])
    {
        if(ft_ct2(str, str1[i]) == 1)
        {
            if(ft_ct1(str1, str1[i], i) == 1)
            {
                write(1, &str1[i], 1);
            }
            
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 3)
    {
        ft_un(argv[1], argv[2]);
    }
    write(1, "\n", 1);
    return (0);
}