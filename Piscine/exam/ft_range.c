
#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
    int i;
    int len;
    int *tab;


    len = (max - min);
    if (len < 1)
    {
        return(NULL);
    }
    
    else
    {
        tab = malloc(sizeof(int) * (len));
        if (!tab)
        {
            return (NULL);
        }

        i = 0;
        while (i < len)
        {
        tab[i] = (min + i);
        i++;
        }
    }
    return (tab);
}

int main()
{
    int min;
    int max;
    int *result;
    int i;


    min = 5;
    max = 10;

    result = ft_range(min, max);
    if (result)
    {
        i = 0;
        while (i < max - min)
        {
            printf("%d", result[i]);
            i++;
        }
    }
}