
#include <unistd.h>

void ft_pustr(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}


int ft_strlen(char*str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}


int main(int argc, char *argv[])
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    len = 0;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                {
                    len++;
                    break;
                }
                j++;
            }
            i++;
        }
        if (len = ft_strlen(argv[1]))
        {
            ft_pustr(argv[1]);
        }
    }
    write(1, "\n", 1);
    return (0);
}