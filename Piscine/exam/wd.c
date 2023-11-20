
#include <stdio.h>
#include <unistd.h>


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
    {
        i++;
    }
    return (i);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    int len;
    int wd;

    len = ft_strlen(argv[1]);

    i = 0;
    j = 0;
    wd = 0;
    while(argv[1][i])
    {
        while (argv[2][j])
        {
            if (argv[1][i] == argv[2][j])
            {
                wd++;
                break;
            }
            j++;

        }
        i++;
    }
    if (wd == len)
    {
        ft_putstr(argv[1]);
    }

}