#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
    if (nbr == -2147483648)
    {
        write (1, "-2147483648", 11);
        return;
    }
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
    }
    if (nbr <= 9)
        ft_putchar(nbr + '0');
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}
/*
void ft_number(int number)
{
    if (number > 9)
        ft_number(number / 10);
    write(1, &"0123456789"[number %10], 1);
}
*/

int main(void)
{
    int number;

    number = 1;
    while (number <= 100)
    {
        if (number %3 == 0 && number % 5 == 0)
            write(1, "good", 4);
        else if (number %3 == 0)
            write(1, "bon", 3);
        else if (number %5 == 0)
            write(1, "bad", 3);
        else 
            ft_putnbr(number);
        write(1, "\n", 1);
        number++;
    }
}