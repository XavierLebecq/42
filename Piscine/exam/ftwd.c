
#include <unistd.h>

char *ft_putstr(char *str)
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

void ft_wd(char *str, char *str1)
{
    int i;
    int j;
    int len;
    int count;

    i = 0;
    j = 0;
    count = 0;
    
    len = ft_strlen(str);
    while (str[i])
    {
        while (str1[j])
        {
            if (str[i] == str1[j])
            {
                count++;
                break;
            }
            j++;
        }
        i++;
    }
    if (len == count)
    {
        ft_putstr(str);
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        ft_wd(argv[1], argv[2]);
    }
    write(1, "\n", 1);
}