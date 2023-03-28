/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:11:13 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:11:14 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Open the file and storage the content in one struct
int	ft_open_map(char *map, t_map_data *map_data)
{
	int			fd;

	if (!map_data)
		return (0);
	map_data->first_read_matrice = ft_read_count_map(map);
	if (!map_data)
		return (0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!ft_map_extension(map))
	{
		close (fd);
		return (0);
	}
	if (!ft_read_map(fd, map_data))
	{
		close (fd);
		free(map_data->matrice);
		free(map_data);
		return (0);
	}
	close (fd);
	free (map_data->matrice[0]);
	//free (map_data);
	return (1);
}

// Function to read and count the map content for ft_calloc in the next function
// [  ] Take only the number of lines
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
			/*
			if (buffer[i] == '\n') // alterei apenas o != para == e adicionei o == '\0'
				count++;
			if (buffer[i] == '\0')
				break ;
				*/
			if (buffer[i] != '\n')
				count++;
			i++;
		}
	}
	if (close(fd) == -1)
		return (0);
	return (count);
}

// Read the file and storage the content in one struct
int	ft_read_map(int fd, t_map_data *map_data)
{
	int		i;
	char	*buffer;

	map_data->matrice = ft_calloc(map_data->first_read_matrice, sizeof(char *));
	ft_printf("\n%d\n", map_data->first_read_matrice);
	if (!map_data->matrice)
		return (0);
	i = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		map_data->matrice[i] = buffer;
		i++;
	}
	if (map_data == NULL || map_data->matrice == NULL
		|| map_data->matrice[0] == NULL)
		return (0);
	if (!ft_map_dimensions(map_data))
		return (0);
	if (!ft_is_valid_map(map_data))
		return (0);
	return (1);
}

// Counts the number of rows, columns and size in matrice 
int	ft_map_dimensions(t_map_data *map_data)
{
	int		row_index;
	char	*row;
	char	*first_row;
	int		row_len;

	row_index = 0;
	first_row = map_data->matrice[0];
	while (first_row[map_data->cols_matrice] && first_row[map_data->cols_matrice] != '\n')
		map_data->cols_matrice++;
	while (map_data->matrice[row_index])
	{
		row = map_data->matrice[row_index];
		row_len = ft_strlen(row);
		if (row[row_len - 1] == '\n')
			row_len--;
		if (row_len != map_data->cols_matrice)
		{
			map_data->rows_matrice = 0;
			return (0);
		}
		map_data->rows_matrice++;
		row_index++;
	}
	map_data->size_matrice = map_data->rows_matrice * map_data->cols_matrice;
	
	map_data->resolutions.settings_map_width = map_data->cols_matrice;
	map_data->resolutions.settings_map_height = map_data->rows_matrice;

	ft_printf("Width: %d e Height: %d\n", map_data->resolutions.settings_map_width, map_data->resolutions.settings_map_height);

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
