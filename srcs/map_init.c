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

// Open the file and storage the content in one struct
int	ft_open_map(char *map, t_game_instance *game_init)
{
	int			fd;

	game_init->map_init.first_read_matrice = ft_read_count_map(map);
	if (!&game_init->map_init)
	{
		free(game_init->map_init.matrice);
		return (0);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!ft_map_extension(map))
	{
		close (fd);
		return (0);
	}
	if (!ft_read_map(fd, game_init))
	{
		close (fd);
		return (0);
	}
	close (fd);
	return (1);
}

// Function to read and count the map content for ft_calloc in the next function
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

// Function to read the map
int	ft_read_map(int fd, t_game_instance *game_init)
{
	int		i;
	char	*buffer;

	game_init->map_init.matrice = ft_calloc(game_init->map_init.first_read_matrice + 1, sizeof(char *));
	ft_printf("\n%d\n", game_init->map_init.first_read_matrice);

	if (!game_init->map_init.matrice)
	{
		free(game_init->map_init.matrice);
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
	if (!game_init->map_init.matrice || !ft_map_dimensions(game_init) || !ft_is_valid_map(game_init))
	{
		free(game_init->map_init.matrice);
		return (0);
	}
	return (1);
}

// Counts the number of rows, columns and size in matrice 
int	ft_map_dimensions(t_game_instance *game_init)
{
	int		row_index;
	char	*row;
	char	*first_row;
	int		row_len;

	row_index = 0;
	first_row = game_init->map_init.matrice[0];
	while (first_row[game_init->map_init.cols_matrice] && first_row[game_init->map_init.cols_matrice] != '\n')
		game_init->map_init.cols_matrice++;
	while (game_init->map_init.matrice[row_index])
	{
		row = game_init->map_init.matrice[row_index];
		row_len = ft_strlen(row);
		if (row[row_len - 1] == '\n')
			row_len--;
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

// Check if the map has a valid .ber extension and if there's a valid path
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
