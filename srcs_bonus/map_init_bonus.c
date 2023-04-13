/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:01:09 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 17:01:10 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
	if (!game_init->map_init.first_read_matrice
		|| game_init->map_init.first_read_matrice < 3)
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

// Function to count the content for ft_calloc (reserved space to ft_read_map()
int	ft_read_count_map(char *map)
{
	int		fd;
	int		count;
	char	buffer[BUFFER_SIZE];

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	count = count_newlines(fd, buffer);
	if (close(fd) == -1)
		return (0);
	count++;
	return (count);
}

// Function to reads a map from a file, validates it, and put in game instance
int	ft_read_map(int fd, t_game_instance *game_init)
{
	int		i;
	char	*buffer;

	game_init->map_init.matrice
		= ft_calloc(game_init->map_init.first_read_matrice + 1, sizeof(char *));
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
	ft_check_read(game_init);
	return (1);
}

// Function to ounting the number of rows, columns and matrice
int	ft_update_map_dimensions(t_game_instance *game_init)
{
	if (!ft_map_dimensions(game_init))
		return (0);
	game_init->map_init.size_matrice = game_init->map_init.rows_matrice
		* game_init->map_init.cols_matrice;
	game_init->map_init.resolutions.settings_map_width
		= game_init->map_init.cols_matrice;
	game_init->map_init.resolutions.settings_map_height
		= game_init->map_init.rows_matrice;
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
