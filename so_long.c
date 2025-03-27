/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:26:06 by kemzouri          #+#    #+#             */
/*   Updated: 2025/03/27 01:19:08 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h> //delete later

int	main(int argc, char *argv[])
{
	t_map	*game;

	if (argc != 2)
		return (1);
	if (is_valid_filename(argv[1]) == 0)
		return (1);
	game = malloc(sizeof(t_map));
	memset(game, 0, sizeof(t_map)); // ATTENTION FT_MEMSET NEEDED
	if (game == NULL)
		return (1);
	if (calculate_map_height(argv[1]) == 0)
		return (free(game), 1);
	game->height = calculate_map_height(argv[1]);
	store_map_in_array(argv[1], game);
	if (check_map_validity(game) == 0)
		return (free_2d_array(game->map), free(game), 1);
	game_load(game);
	ft_free(game);
}
