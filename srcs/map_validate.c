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
int	ft_is_valid_map(t_map_data *data)
{
	t_map_objects_counts	counts;

	ft_printf("\n Eu entrei na função ft_is_valid\n");
	if (!ft_is_rectangular_and_square(data))
		return (0);
	if (!ft_is_wall(data))
		return (0);
	if (!ft_count_map_objects(data, &counts))
		return (0);
	ft_printf("\n Eu sai da função ft_is_valid\n");
	return (1);
}

// Check if the map is rectangular/square
int	ft_is_rectangular_and_square(t_map_data *data)
{
	int	i;
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	i = 0;
	while (data->matrice[i] != NULL)
	{
		ft_printf("%s\n", data->matrice[i]); //debugando a matriz
		if (data->matrice[i][0] == '\n')
		{
			if (cols == 0)
				cols = i;
			else if (i - cols != 1)
				return (0);
			rows++;
		}
		i++;
	}
	if (rows + 1 != cols || rows != data->rows - 2 || cols != data->cols - 1)
		return (0);
	
	data->rows = rows;
	data->cols = cols;
	return (1);
}


// Check if the map is closed/surrounded by walls
int ft_is_wall(t_map_data *data)
{
	int i;

	i = 0;
	while (i < data->cols)
	{
		if (data->matrice[0][i] != WALL || data->matrice[data->rows - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < data->rows)
	{
		if (data->matrice[i][0] != WALL || data->matrice[i][data->cols - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

// Counts the content in the map and if the map must contain 1 exit, 1 starting position, and at least 1 collectible
int	ft_count_map_objects(t_map_data *data, t_map_objects_counts *counts)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = data->matrice;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == PLAYER)
				counts->count_player++;
			else if (map[i][j] == EXIT)
				counts->count_exit++;
			else if (map[i][j] == COLLECTIBLE)
				counts->count_collectible++;
			else if (map[i][j] == WALL)
				counts->count_wall++;
			else if (map[i][j] == EMPTY)
				counts->count_empty++;
			else if (map[i][j] != '\n')
				return(0); // Check if the map as invalid if there are invalid characters
			j++;
		}
		i++;
	}
	if (!(counts->count_player == 1 && counts->count_exit == 1 && counts->count_collectible >= 1))
		return(0);
	return(1);
}

// Check if the map have a valid .ber extension and check if there’s a valid path/
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
	{
		ft_error_map(24);
		return (0);
	}
	else if (file_extension && !ft_strcmp(file_extension, extension))
	{
		if (file_count >= max_files)
		{
			ft_error_map(24);
			return (0);
		}
		file_count++;
	}
	else
		return (0);
	return (1);
}

/* 
int	ft_is_valid_character(t_map_data *data)
{
	char	*str;
	int		i;

	i = 0;
	str = data->matrice;
	while(str[i] != '\0') 
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'E' && str[i] != 'P')
			return (0);
		i++;
	}
	return (1);
}
*/
