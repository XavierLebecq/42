

#include <unistd.h>
char  putnbr(int nbr)
{
	if (nbr < 10)
	{
		nbr = nbr + '0';
		write (1, &nbr, 1);
	}
	else if (nbr >= 10)
	{
		putnbr(nbr / 10);
		putnbr(nbr % 10);
	}
	return (nbr);
}


void	write_number(int nbr)
{
	char str[10] = "0123456789";
	if (nbr > 9)
		write_number(nbr / 10);
	write (1, &str[nbr % 10], 1);
}
int main()
{
	int	i = 1;

	while (i <= 100)
	{
		if (i % 15 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 5 == 0) 
			write (1, "buzz", 4);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else
		{
			write_number(i);
		}
		i++;
		write(1, "\n", 1);
	}
}
