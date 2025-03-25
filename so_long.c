#include "so_long.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (1);
    if (is_valid_filename(argv[1]) == 0)
        return (1);
    t_map *game = malloc(sizeof(t_map)); // free **map avant de free game
    if (calculate_map_height(argv[1]) == 0)
        return (1);
    // game->height = calculate_map_height(argv[1]);
    // printf("%d", game->height);
    free(game);
}
