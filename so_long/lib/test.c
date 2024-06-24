#include "lib.h"

int main()
{
    int fd;

    char *path= "map.ber";
    char *line;
    fd = open(path, O_RDONLY);

    
    line = get_next_line(fd);
    while (line)
    {
        ft_printf("line: %s\n", line);
        free(line);
        line = get_next_line(fd);
    }
    // ft_printf("line: %s\n", line);
    // free(line);
    close(fd);
}