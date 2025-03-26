/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:25:50 by kemzouri          #+#    #+#             */
/*   Updated: 2025/03/26 01:04:04 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calculate_map_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (line == NULL)
		return (close(fd), ft_putstr_fd("Error\nEmpty file\n", 2), 0);
	if (line[0] == '\n' && line[1] == '\0')
	{
		close(fd);
		get_next_line(-1);
		return (free(line),
			ft_putstr_fd("Error\nMap cannot start with a newline\n", 2), 0);
	}
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), height);
}

void	store_map_in_array(char *filename, t_map *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (line[ft_strln(line) - 1] == '\n')
		line[ft_strln(line) - 1] = '\0';
	game->map = malloc((game->height + 1) * sizeof(char *));
	while (line != NULL)
	{
		game->map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strln(line) - 1] == '\n')
			line[ft_strln(line) - 1] = '\0';
	}
	game->map[i] = NULL;
	close(fd);
}
