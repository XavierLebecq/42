
#include <stdio.h>
#include <unistd.h>

void ft_last(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    i--;
    while (str[i] == ' ')
        i--;

    while (str[i] >= 'a' && str[i] <= 'z')
        i--;
    i++;
    while (str[i] != ' ')
    {
        write (1, &str[i], 1);
        i++;
    }    
    write(1, "\n", 1);
}


int main(int argc, char *argv[])
{
    char str[] = " nnkkk jhjhhjhj ";
    ft_last(str);
}