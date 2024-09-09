int	count_words(char *str)
{
	int	i;
    int word;
    int count;
    
    i = 0;
    word = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] != ' ')
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
    return(count);
}
    
int	main(void)
{
	char str1[] = "";

	count_words(str1);
    printf("%d\n", count_words(str1));
	return (0);
}