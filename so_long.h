/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:26:02 by kemzouri          #+#    #+#             */
/*   Updated: 2025/03/27 18:20:04 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define TILE_SIZE 64

typedef struct s_map
{
	char	**map;
	char	**clone_map;
	int		x;
	int		y;
	int		height;
	int		width;
	int		len;
	int		collectibles;
	int		p;
	int		x_pos;
	int		y_pos;
	int		e;
	int		ff_c;
	int		ff_e;
	int		win_height;
	int		win_width;
	void	*mlx;
	void	*mlx_window;
	void	*f_image;
	void	*d_image;
	void	*p_image;
	void	*w_image;
	void	*c_image;
	int		image_width;
	int		image_height;
	int		press_x;
	int		press_y;
}			t_map;

int			ft_strln(char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			calculate_map_height(char *filename);
void		store_map_in_array(char *filename, t_map *game);
int			is_valid_filename(char *str);
void		free_2d_array(char **map);
int			check_map_shape(t_map *game);
int			check_char(char *str, char c);
int			is_map_surrounded(t_map *game);
int			check_map_validity(t_map *game);
int			is_valid(char **map);
void		initialize(t_map *game);
void		count_element(t_map *game);
int			valid_characters(t_map *game);
void		clone_map(t_map *game);
void		flood_fill(t_map *game, int x, int y);
int			ff_validity(t_map *game);

void		display_window(t_map *game);
void		game_load(t_map *game);
void		ft_free(t_map *game);
void		handle_events(t_map *game);
void		ft_free_images(t_map *game);
void		init_images(t_map *game);
int			key_hook(int keycode, t_map *game);
void		move_player(t_map *game);
int	close_game(t_map *game);



#endif
