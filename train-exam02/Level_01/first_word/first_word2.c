#include <unistd.h>
#include <stdio.h>

void ft_first_word(char **argv)
{
	int i;
	
	i = 0;
	while (argv[1][i])
	{
		while (argv[1][i] &&  (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		while ((argv[1][i]) && (argv[1][i] != ' ') && (argv[1][i] != '\t'))
		{
			write (1, &argv[1][i], 1);
			i++;
		}
		write (1, "\n", 1);
		break;
	}
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	else
	{		
		ft_first_word(argv);
	}
}
