
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
    if (nbr <= 9)
    {     
        ft_putchar(nbr + 48)
    }
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}


int main()
{
    int number;

    number = 1;
    while (number <= 100)
    {
        if (number % 3 == 0 && number % 5 == 0)
            write(1, "fizzbuzz", 9);
        else if (number % 3 == 0)
            write (1, "fizz", 4);
        else if (number % 5 == 0)
            write (1, "buzz", 4);
        else
        {
            ft_putnbr(number);
        }
        write(1, "\n", 1);
        number++;
    }
}