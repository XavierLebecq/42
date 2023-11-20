#include <unistd.h>
#include <stdio.h>

int ft_cw(char *str)
{
    int i;
    int count;
    int pos;

    i = 0;
    count = 0;
    pos = 1;

    while (str[i])
    {
        if (str[i] != ' ')
        {
            if (pos == 1)
            {
                count++;
                pos = 0;
            }

        }
        else if (str[i] == ' ')
        {
            pos = 1;
        }
        i++;
    }
    return (count);

}


int main (int argc, char **argv)
{
    if (argc == 2);
    {
        printf ("%d", ft_cw(argv[1]));
    }
    write(1, "\n", 1);
}