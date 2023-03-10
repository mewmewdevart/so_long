/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:12:31 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:12:32 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Check if the all conditions is valid or not
int	ft_is_valid_map(t_map *data)
{
	/* &data[0] é o endereço da estrutura t_map que contém a matriz de caracteres 
	&& is_wall(data->matrice) && is_content(data->matrice) */
	if (is_rectangular(&data[0]))
		return (1);
	return (-1);
}

//Check if the map is rectangular
int	is_rectangular(t_map *data)
{
	int	char_index;

	char_index = -1;
	while (data->matrice[++char_index])
	{
		if (data->matrice[char_index] == '\n')
		{
			if (ft_check_cols(data->cols, data) == -1)
				return (-1);
			data->rows++;
			if (data->cols == 0)
				data->cols = char_index;
		}
	}
	if (ft_check_cols(data->cols, data) == -1)
		return (-1);
	if (ft_count_cols_rows(data) == -1)
		return (-1);
	return (1);
}

//Checks if the number of columns is the same in all rows of the map
int	ft_check_cols(int cols_count, t_map *data)
{
	if (data->cols == 0)
		data->cols = cols_count;
	else if (cols_count != data->cols)
	{
		ft_error_map("Invalid map! The lines are not the same size.", 61);
		return (-1);
	}
	return (1);
}

// Checks if the number of columns is more big than the number of rows
int	ft_count_cols_rows(t_map *data)
{
	if (!(data->cols > data->rows))
		return (-1);
	return (1);
}
//Check if the map is closed/surrounded by walls
int	is_wall(char *map);

//The map must contain 1 exit, 1 starting position and at least 1 collectible
int	is_content(char *map);

//Check if the map have a valid .ber extension and path/
int	ft_map_extension(char *map)
{
	char		*extension;
	char		*file_extension;
	static int	file_count = 0;
	const int	max_files = 1;

	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if (map[ft_strlen(map) - 1] == '/')
	{
		ft_error_map(map, 21);
		return (-1);
	}
	else if (file_extension && ft_strcmp(file_extension, extension) == 0)
	{
		if (file_count >= max_files)
		{
			ft_error_map(map, 24);
			return (-1);
		}
		file_count++;
	}
	else
		return (-1);
	return (1);
}
