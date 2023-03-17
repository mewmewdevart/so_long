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

// Check if the all conditions is valid or not
int ft_is_valid_map(t_map_data *data)
{
	t_map_objects_counts	counts = {0};
	ft_printf("\n Eu entrei na função ft_is_valid\n");

	if(!(ft_is_rectangular_and_square(data)))
		return (0);
	if(!(ft_is_wall(data)))
		return (0);
	if(!(ft_count_map_objects(data, &counts)))
		return (0);
	ft_printf("\n Eu sai da função ft_is_valid\n");
	return (1);
}

// Check if the map is rectangular/square
int ft_is_rectangular_and_square(t_map_data *data)
{
	int i;
	int num_cells;

	i = 0;
	ft_printf("\n Eu entrei na função ft_is_rectangular_and_square\n");
	if(data->matrice[i] == NULL || ft_isspace(*data->matrice[i]))
		return(0);
	while (data->matrice[i] != NULL)
	{
		if (data->matrice[i][0] == '\n')
		{
			if (data->cols == 0)
				data->cols = ft_strlen(data->matrice[i - 1]);
			else if (ft_strlen(data->matrice[i - 1]) != (size_t)data->cols)
				return (0);
			data->rows++;
		}
		i++;
	}
	if (data->rows != data->cols)
	{
		if (data->cols == 0 || data->rows == 0)
			return (0);
		else
			return (1);
	}
	else
	{
		num_cells = data->rows * data->cols;
		if (num_cells != (data->rows * (data->rows + 1) * (2 * data->rows + 1)) / 6)
			return (0);
	}
	return (1);
}

// Check if the map is closed/surrounded by walls
int ft_is_wall(t_map_data *data)
{
	int i;
	int j;
	int missing_walls;

	ft_printf("\n Eu entrei na função ft_is_wall\n");
	i = 0;
	while (i < data->rows) {
		j = 0;
		while (j < data->cols) {
			// Verifica se estamos nas bordas da matriz
			if (i == 0 || j == 0 || i == data->rows - 1 || j == data->cols - 1) 
			{
				// Verifica se a célula atual é uma parede
				if (data->matrice[i][j] != WALL) {
					missing_walls++;
				}
			}
			j++;
		}
		i++;
	}
	ft_printf("\n Eu sai da na função ft_is_wall\n");
	return (missing_walls == 1);
}

// Count map content and check if it has (1)E, 1(E) and >= 1(C)
int	ft_count_map_objects(t_map_data *data, t_map_objects_counts *counts)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\n Eu entrei na função ft_count_map_objects\n");
	while (data->matrice[i] != NULL)
	{
		j = 0;
		while (data->matrice[i][j] != '\0')
		{
			if (data->matrice[i][j] == PLAYER)
				counts->count_player++;
			else if (data->matrice[i][j] == EXIT)
				counts->count_exit++;
			else if (data->matrice[i][j] == COLLECTIBLE)
				counts->count_collectible++;
			else if (data->matrice[i][j] == WALL)
				counts->count_wall++;
			else if (data->matrice[i][j] == EMPTY)
				counts->count_empty++;
			else if (data->matrice[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	if (!(counts->count_player == 1 && counts->count_exit && counts->count_collectible >= 1))
		return (0);
	return (1);
}

// Check if the map has a valid .ber extension and if there's a valid path
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
		ft_error_map(21);
		return (0);
	}
	else if (!file_extension || !ft_strcmp(file_extension, ""))
		return (0);
	else if (file_extension && !ft_strcmp(file_extension, extension))
	{
		if (file_count >= max_files)
			return (0);
		file_count++;
	}
	else
		return (0);
	return (1);
}
