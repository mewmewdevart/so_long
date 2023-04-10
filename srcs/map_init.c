/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:37:25 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/30 14:47:57 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to open and read the map file
int	ft_open_map(char *map, t_game_instance *game_init)
{
	int			fd;

	if (!ft_map_extension(map))
		return (0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	game_init->map_init.first_read_matrice = ft_read_count_map(map);
	if (!game_init->map_init.first_read_matrice)
	{
		close (fd);
		ft_free_map(game_init);
		return (0);
	}
	if (!ft_read_map(fd, game_init))
	{
		close (fd);
		ft_free_map(game_init);
		return (0);
	}
	close (fd);
	return (1);
}

// Function to count the map content for ft_calloc (reserved space to ft_read_map() function)
int	ft_read_count_map(char *map)
{
	int		i;
	int		fd;
	int		count;
	char	buffer[BUFFER_SIZE];
	ssize_t	n_read;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read < 0)
			return (0);
		if (n_read == 0)
			break ;
		i = 0;
		while (i < n_read)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
	}
	if (close(fd) == -1)
		return (0);
	count++;
	return (count);
}

// Function to reads a map from a file, validates it, and sets it in the game instance
int	ft_read_map(int fd, t_game_instance *game_init)
{
	int		i;
	char	*buffer;

	game_init->map_init.matrice = ft_calloc(game_init->map_init.first_read_matrice + 1, sizeof(char *));
	if (!game_init->map_init.matrice)
	{
		ft_free_map(game_init);
		return (0);
	}
	i = 0;
	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		game_init->map_init.matrice[i] = buffer;
		i++;
	}
	if (game_init->map_init.matrice[0] == NULL || !ft_map_dimensions(game_init) || !ft_is_valid_map(game_init))
	{
		ft_free_map(game_init);
		return (0);
	}
	return (1);
}

// Function to calculate the dimensions of the game map by counting the number of rows, columns and matrice
int	ft_map_dimensions(t_game_instance *game_init)
{
	char	*row;
	int		row_len;
	int		row_index;

	row_index = 0;
	row = game_init->map_init.matrice[0];
	while (row[game_init->map_init.rows_matrice] && row[game_init->map_init.cols_matrice] != '\n')
		game_init->map_init.cols_matrice++;
	while (1)
	{
		row = game_init->map_init.matrice[row_index];
		if (!row)
			break ;
		row_len = ft_strlen(row) - (row[ft_strlen(row) - 1] == '\n');
		if (row_len != game_init->map_init.cols_matrice)
		{
			game_init->map_init.rows_matrice = 0;
			return (0);
		}
		game_init->map_init.rows_matrice++;
		row_index++;
	}
	game_init->map_init.size_matrice = game_init->map_init.rows_matrice * game_init->map_init.cols_matrice;
	game_init->map_init.resolutions.settings_map_width = game_init->map_init.cols_matrice;
	game_init->map_init.resolutions.settings_map_height = game_init->map_init.rows_matrice;
	return (1);
}

// Function to checks if the map has a valid .ber extension and path/
int	ft_map_extension(char *map)
{
	char		*extension;
	char		*file_extension;
	static int	file_count;

	file_count = 0;
	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if (map[ft_strlen(map) - 1] == '/')
	{
		ft_error_map(21);
		return (0);
	}
	else if (!file_extension || !ft_strcmp(file_extension, ""))
		return (0);
	else if (file_extension && !ft_strcmp(file_extension, extension))
	{
		if (file_count >= MAX_FILES)
			return (0);
		file_count++;
	}
	else
		return (0);
	return (1);
}
