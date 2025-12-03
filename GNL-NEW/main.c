#include <fcntl.h>     // open()
#include <stdio.h>     // printf()
#include <stdlib.h>    // free()

char    *get_next_line(int fd);

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc == 1)
    {
        // No file provided → read from STDIN
        fd = 0;
        printf("Reading from STDIN. Type lines:\n");
    }
    else
    {
        // Open the file provided as argument
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            perror("open");
            return (1);
        }
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
	line = get_next_line(fd);
	printf("LINE: %s", line);
    free(line);
    return (0);
}
