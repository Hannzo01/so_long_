/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:54:21 by kemzouri          #+#    #+#             */
/*   Updated: 2025/03/28 16:29:01 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_window(t_map *game)
{
	game->win_height = game->height * TILE_SIZE;
	game->win_width = game->width * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nFailed to initialize mlx.\n", 2);
		ft_free(game);
		exit(1);
	}
	game->mlx_window = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "so_long");
	if (!game->mlx_window)
	{
		ft_putstr_fd("Error\nFailed to create window.\n", 2);
		ft_free(game);
		exit(1);
	}
}

void	ft_free(t_map *game)
{
	if (game->clone_map)
		free_2d_array(game->clone_map);
	if (game->map)
		free_2d_array(game->map);
	if (game->mlx_window)
		mlx_destroy_window(game->mlx, game->mlx_window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

int	key_hook(int keycode, t_map *game)
{
	if (keycode == 65307)
	{
		ft_free_images(game);
		ft_free(game);
		exit(0);
	}
	game->press_x = 0;
	game->press_y = 0;
	if (keycode == 119)
		game->press_y = -1;
	else if (keycode == 97)
		game->press_x = -1;
	else if (keycode == 100)
		game->press_x = 1;
	else if (keycode == 115)
		game->press_y = 1;
	if (move_player(game) == 1 && (keycode == 119 || keycode == 97
			|| keycode == 100 || keycode == 115))
	{
		game->move_count++;
		write(1, "Moves:", 6);
		ft_putnbr(game->move_count);
		write(1, "\n", 1);
	}
	return (0);
}

int	close_game(t_map *game)
{
	ft_free_images(game);
	ft_free(game);
	exit(0);
}
