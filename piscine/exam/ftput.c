#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}


void ft_putnbr(int nbr)
{
    if (nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (nbr < 0)
    {
        nbr = -nbr;
        ft_putchar('-');

    }
    if (nbr < 10)
    {
        ft_putchar(nbr + 48);
    }
    if (nbr > 9)
    {
        ft_putnbr(nbr /10);
        ft_putnbr(nbr % 10);
    }
}

int main()
{
    ft_putnbr(-12);
}