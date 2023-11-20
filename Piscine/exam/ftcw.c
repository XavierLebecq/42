#include <stdio.h>

int main (int argc, char **argv)
{

    int i;
    int count;
    int pos;

    i = 0;
    count = 0;
    pos = 1;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] != ' ')
            {
                if(pos == 1)
                {
                    count++;
                    pos = 0;
                }
            }
            else
            {
                pos = 1;
            }
            i++;    
        }
    }
    printf("%d", count);

}