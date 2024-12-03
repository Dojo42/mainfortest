#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
	size_t	nb_line = 1;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%zu : %s", nb_line, line);
		nb_line++;
        free(line);
    }

    if (line == NULL)
    {
        printf("\nEnd of file reached or error occurred.\n");
    }

    close(fd);
    
    return 0;
}
