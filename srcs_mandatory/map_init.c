/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:37:25 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 14:53:57 by larcrist         ###   ########.fr       */
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

// Function to count the map content for ft_calloc
// (reserved space to ft_read_map() function)
int	ft_read_count_map(char *map)
{
	int	fd;
	int	count;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	count = ft_count_lines(fd);
	if (close(fd) == -1)
		return (0);
	return (count);
}

int	ft_count_lines(int fd)
{
	int		count;
	char	buffer[BUFFER_SIZE];
	ssize_t	n_read;
	int		i;

	count = 0;
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
	count++;
	return (count);
}

// Function to reads a map from a file, validates it, and sets
//		it in the game instance
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
	if (!ft_check_read(game_init))
		return (0);
	return (1);
}

int	ft_check_read(t_game_instance *game_init)
{
	if (game_init->map_init.matrice[0] == NULL
		|| !ft_map_dimensions(game_init) || !ft_is_valid_map(game_init))
	{
		ft_free_map(game_init);
		return (0);
	}
	return (1);
}
