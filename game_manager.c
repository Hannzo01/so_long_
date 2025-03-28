/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:57:46 by kemzouri          #+#    #+#             */
/*   Updated: 2025/03/28 01:48:21 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_map *game)
{
	game->image_height = 64;
	game->image_width = 64;
	game->p_image = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
			&game->image_width, &game->image_height);
	game->d_image = mlx_xpm_file_to_image(game->mlx, "./textures/door.xpm",
			&game->image_width, &game->image_height);
	game->f_image = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&game->image_width, &game->image_height);
	game->c_image = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectibles.xpm", &game->image_width,
			&game->image_height);
	game->w_image = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->image_width, &game->image_height);
	if (game->p_image == NULL || game->d_image == NULL || game->f_image == NULL
		|| game->c_image == NULL || game->w_image == NULL)
	{
		ft_free_images(game);
		return ;
	}
}

void	ft_free_images(t_map *game)
{
	if (game->d_image != NULL)
		mlx_destroy_image(game->mlx, game->d_image);
	if (game->p_image != NULL)
		mlx_destroy_image(game->mlx, game->p_image);
	if (game->f_image != NULL)
		mlx_destroy_image(game->mlx, game->f_image);
	if (game->c_image != NULL)
		mlx_destroy_image(game->mlx, game->c_image);
	if (game->w_image != NULL)
		mlx_destroy_image(game->mlx, game->w_image);
}

void	display_images(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->c_image, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->d_image, j * 64, i * 64);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->p_image, j * 64, i * 64);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->w_image, j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->f_image, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
void	handle_door(t_map *game)
{
	if (game->collected == game->collectibles)
	{
		ft_free_images(game);
		ft_free(game);
		exit(0);
	}
	// handle if the collectible are not collected yet
}

int	move_player(t_map *game)
{
	game->future_x = game->x_pos + game->press_x;
	game->future_y = game->y_pos + game->press_y;
	if (game->map[game->future_y][game->future_x] == 'E')
		handle_door(game);
	if (game->map[game->future_y][game->future_x] != '1')
	{
		if (game->map[game->future_y][game->future_x] == 'C')
			game->collected++;
		game->map[game->y_pos][game->x_pos] = '0';
		game->x_pos = game->future_x;
		game->y_pos = game->future_y;
		game->map[game->y_pos][game->x_pos] = 'P';
		display_images(game);
		return (5);
	}
	return (0);
}

void	game_load(t_map *game)
{
	display_window(game);
	init_images(game);
	display_images(game);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
