#include <unistd.h>


int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if(argv[1][i] == 'a')
            {
                write(1, &argv[1][i], 1);
                break;
            }
        }
    }
    write(1, "\n", 1);
}