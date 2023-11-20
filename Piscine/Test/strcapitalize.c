#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strlowcase(str);
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if ((str[i - 1] >= 0 && str[i - 1] <= 47) || (str[i - 1] >= 58
					&& str[i - 1] <= 64) || (str[i - 1] >= 123 && str[i
					- 1] <= 127) || (str[i - 1] >= 91 && str[i - 1] <= 96))
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char str[] = "bOnjoUr, _cOmmEnt `ca 42va?";
	printf("%s", ft_strcapitalize(str));
}