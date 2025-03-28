#include "so_long.h"

void	game_load(t_map *game)
{
	display_window(game);
	init_images(game);
	display_images(game);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}

