
#include <stdio.h>

int ft_count_words(char *str)
{
    int i;
    int count;
    int word;

    i = 0;
    count = 0;
    word = 0;

    while (str[i])
    {
        if(str[i] != ' ')
        {
            if (word == 0)
            {
                count++;
                word = 1;
            }
        }
        else
        {
            word = 0;
        }
        i++;
    }

    return (count);
}

int main()
{
    char str[] = " j j j j ";
    printf("%d\n", ft_count_words(str));
}