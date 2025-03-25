#include "so_long.h"

int calculate_map_height(char *filename)
{
    int fd;
    int height;
    char *line;

    height = 0;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (-1);
    line = get_next_line(fd);
    if (line == NULL)
        return (close(fd), ft_putstr_fd("Empty file\n", 2), 0);
    if(line[0] == '\n' && line[1] == '\0')
        return (free(line), close(fd), ft_putstr_fd("Newline only\n", 2), 0);
    while (line != NULL)
    {
        height++;
        free(line);
        line = get_next_line(fd);
    }
    return (close(fd), height);
}
