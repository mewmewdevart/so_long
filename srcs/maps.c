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
int	ft_open_map(char *map)
{
	int			fd;
	t_map_data	*map_data;

	// Aloca memoria para a estrutura t_map_data
	map_data = ft_calloc(1, sizeof(t_map_data));
	if (!map_data)
		return (0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		free (map_data);
		return (-1);
	}
	if (!ft_map_extension(map))
	{
		close (fd);
		free (map_data);
		return (0);
	}
	if (!ft_read_map(fd, map_data))
	{
		close (fd);
		free_map (map_data);
		return (0);
	}
	close (fd);
	free (map_data->matrice[0]);
	free (map_data);
	return (1);
}

// Read the file and storage the content in one struct
int	ft_read_map(int fd, t_map_data *map_data)
{
	int		i;
	char	*buffer;

	map_data->matrice = ft_calloc(6, sizeof(char *)); // Criar uma função que leia o tamanho do mapa e reserve espaço para ser usado em ft_calloc
	i = 0;
    while (1)
    {
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break;
		map_data->matrice[i] = buffer;
		i++;
	}
	if (map_data == NULL || map_data->matrice == NULL || map_data->matrice[0] == NULL)
			return 0;
	if(!ft_map_dimensions(map_data))
		return(0);
	if(!ft_is_valid_map(map_data))
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
	while (first_row[map_data->cols] && first_row[map_data->cols] != '\n') // Conta o numero de colunas
		map_data->cols++;
	while (map_data->matrice[row_index]) // Conta o numero de linhas
	{
		row = map_data->matrice[row_index];
		row_len = ft_strlen(row);
		if (row[row_len - 1] == '\n')
			row_len--;
		if (row_len != map_data->cols)
		{
			map_data->rows = 0;
			return (0);
		}
		map_data->rows++;
		row_index++;
	}
	map_data->size = map_data->rows * map_data->cols;
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
