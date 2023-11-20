
#include <unistd.h>

int ft_ct(char *str, char c, int p)
{
    int i;
    
    i = 0;
    while (i < p)
    {
        if(str[i] == c)
        {
            return(0);
        }
        i++;
    }
    return (1);
}


void ft_i(char *str, char *str1)
{
    int i;
    int j;

    i = 0;
    while (str[i])
    {
        j = 0;
        while (str1[j])
        {
            if(str[i] == str1[j])
            {
                if(ft_ct(str, str[i], i) == 1)
                {
                    write(1, &str[i], 1);
                    break;
                }
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        ft_i(argv[1], argv[2]);
    }
    write(1, "\n", 1);
}