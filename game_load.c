/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:30:51 by kemzouri          #+#    #+#             */
/*   Updated: 2025/03/28 16:30:52 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
