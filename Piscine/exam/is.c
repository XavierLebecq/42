
#include <unistd.h>

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

char *ft_is(char *str)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(str);

    while (i < len)
    {
        write(1, &str[i], 1);
        if (i < len - 1)
        {
            write(1, "   ", 3);
        }
        i++;
    }

}


int main (int argc, char **argv)
{
    if (argc == 2)
    {
        ft_is(argv[1]);
    }
    write (1, "\n", 1);
}