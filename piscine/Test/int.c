#include <stdio.h>
#include <unistd.h>


int ft_control(char *src, char c, int p)
{
    int i;

    i = 0;
    while(i < p)
    {
        if (src[i] == c)
            return (0);
        i++;
    }
    return (1);
}

void ft_int(char *src, char *dest)
{
    int i;
    int j;

    i = 0;
    while (src[i] != '\0')
    {
        j = 0;
        while (dest[j] != '\0')
        {
            if (src[i] == dest[j])
            {
                if(ft_control(src, src[i], i) == 1)
                {
                    write (1, &src[i], 1);
                    break;
                }
            }
            j++;
        }
        i++;
    }
}

int main (int argc, char **argv)
{
    if (argc == 3)
        ft_int(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}